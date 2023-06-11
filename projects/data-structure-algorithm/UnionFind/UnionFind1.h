#include <iostream>
#include <string>
#include <vector>
namespace UF1 {

/// @brief Quick Find 版本

class UnionFind1 {
    std::vector<int> ids; // 存每一个元素的Group ID

public:
    UnionFind1(int n)
    {
        ids.resize(n);
        for (int i = 0; i < n; i++) {
            ids[i] = i;
        }
    }

    int find(int v)
    {
        return ids[v]; // 查找很快
    }

    bool isConnected(int v, int w)
    {
        return find(v) == find(w);
    }

    // 合并O(N)
    void unionElements(int v, int w)
    {
        int vId = find(v);
        int wId = find(w);
        if (vId != wId) {
            for (int i = 0; i < ids.size(); i++) {
                if (ids[i] == vId) {
                    ids[i] = wId;
                }
            }
        }
    }
};
}