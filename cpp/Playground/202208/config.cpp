#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

typedef std::deque<std::string> DEQUE;
using namespace std;

class Section
{
public:
    static Section root()
    {
        return Section("", -1);
    }

    Section(string name, int indent)
        :_name(name), _indent(indent) { }

    string str()
    {
        for (auto& c : children)
        {
            _configs += c.str();
        }
        if (_name.empty())
        {
            return _configs;
        }
        else
        {
            return string(_indent, '\t').append(_name).append(" {\n")
                .append(_configs)
                .append(_indent, '\t').append("}\n");
        }
    }

    Section& add(std::string&& config)
    {
        _configs.append(_indent + 1, '\t').append(config).append("\n");
        return *this;
    }

    Section& child(std::string name)
    {
        return children.emplace_back(name, _indent + 1);
    }

    std::string _name;
    int _indent;
    std::string _configs;
    std::vector<Section> children;
};

struct IpSecConfig
{
    std::string privateKey;
    std::string certificate;

    IpSecConfig()
    {
        if (true)
        {
            privateKey = "/etc/keys.d/private/sok.crk&sig.crk";
            certificate = "/etc/keys.d/certs/sigcert.pem";
        }
        else
        {
            privateKey = "/etc/ipsec.d/certs/nokia-vendor-cert.pem";
            certificate = "/etc/ipsec.d/private/private.pem";
        }
    }

    std::string childSaConf()
    {
        return "# Global defaults for CHILD_SA settings; Applied using include mechanism";
    }

    std::string swanctlConf(const std::map<std::string, std::string>& connPairs) {
        Section swanctl = Section::root();
        auto& connections = swanctl.child("connections");
        auto& bypassConn = connections.child("bypass-conn");
        bypassConn.add("include  /etc/swanctl/conf.d/ike_sa_default.conf");
        auto& bypassChildren = bypassConn.child("children");

        int saId = 0;
        auto nextSaName = [&saId]() {
            return "fhs-sm-" + std::to_string(++saId);
        };

        int tunnelId = 0;
        for (auto [remoteIp, localIp] : connPairs) {
            auto addBypassChild = [&](std::string localProtocol, std::string remoteProtocol) {
                bypassChildren.child(nextSaName())
                    .add("start_action=trap")
                    .add("mode=pass")
                    .add("local_ts=" + localIp + localProtocol)
                    .add("remote_ts=" + remoteIp + remoteProtocol)
                    .add("policies=yes");
            };
            addBypassChild("/32[6/22]", "/32[6/]");
            addBypassChild("/32[17/68]", "/32[17/67]");

            auto& tunnelConn = connections.child("tunnel-conn-" + std::to_string(++tunnelId));
            tunnelConn.add("include  /etc/swanctl/conf.d/ike_sa_default.conf")
                .add("keyingtries=1")
                .add("reauth_time=0s")
                .add("rekey_time=86400s")
                .add("version=2")
                .add("remote_addrs=" + remoteIp + "")
                .add("local_addrs=" + localIp + "")
                .add("proposals=aes256gcm16-prfsha384-ecp384, default")
                .add("dpd_delay=10");

            auto& tunnelConnChilldren = tunnelConn.child("children");
            auto addTunnelChild = [&](std::string protocol) {
                tunnelConnChilldren.child(nextSaName())
                    .add("start_action=start")
                    .add("mode=tunnel")
                    .add("esp_proposals=aes256gcm16, default")
                    .add("local_ts=" + localIp + protocol)
                    .add("remote_ts=" + remoteIp + protocol)
                    .add("dpd_action=clear");
            };

            addTunnelChild("/32[6/]");
            addTunnelChild("/32[17/]");
        }

        swanctl.child("pools");
        swanctl.child("authorities");
        swanctl.child("secrets").child("private").add("file=" + privateKey);

        return swanctl.str();
    }

    std::string ikeSaConf()
    {
        auto conf = Section::root();
        conf.add("# Global defaults for IKE_SA settings; Applied using include mechanism\n")
            .add("unique=no")
            .add("mobike=no")
            .add("fragmentation=yes");
        conf.child("local").add("auth = pubkey").add("certs=" + certificate);
        conf.child("remote").add("tid=%any");
        return conf.str();
    }
};

int main()
{
    std::map<std::string, std::string> pair;
    pair["192.168.1.1"] = "172.168.1.2";
    pair["192.168.1.2"] = "172.168.1.3";
    std::string s2 = IpSecConfig().swanctlConf(pair);
    std::string s3 = IpSecConfig().ikeSaConf();
    cout << s3;
    return 0;
}
