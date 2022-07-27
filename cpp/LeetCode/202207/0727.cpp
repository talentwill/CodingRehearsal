#include "../helper.h"

class Solution1 {
public:
    struct TrieNode {
        std::map<char, TrieNode*> children;
    } root;

    // 构建后缀树，单词从后往前遍历，因为前缀单词不用计算长度，所以不需要标记变量
    void buildTrie(vector<string>& words) {
        for (auto& w : words) {
            TrieNode* node = &root;
            for (int i = w.size() - 1; i >= 0; i--) { 
                char c = w[i];
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
        }
    }

    int minimumLengthEncoding(vector<string>& words) {
        buildTrie(words);
        dfs(&root, 1);
        return len;
    }

    int len = 0;
    // 深度优先用来计算从根节点到叶子节点到路径，将路径长度累加到len里。
    void dfs(TrieNode* node, int depth) {
        if (node != nullptr) {
            // 判断是否为叶子节点
            if (node->children.empty()) {
                len += depth;
            }
            else {
                for (auto [k, v] : node->children) {
                    dfs(v, depth + 1);
                }
            }
        }   
    }
};

int main()
{
    vector<string> words = {"time", "me", "bell"}; // time#bell# = 10
    Solution1().minimumLengthEncoding(words);
    return 0;
}
