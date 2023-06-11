#include <iostream>
#include <string>
#include <vector>
namespace UF4 {

/// @brief Quick Union + 按照子树的高度优化

class UnionFind4 {
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind4(int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v)
    {
        if (parent[v] != v) {
            return find(parent[v]); // 返回祖先ID，不压缩
        }
        return parent[v];
    }

    bool isConnected(int v, int w)
    {
        return find(v) == find(w);
    }

    void unionElements(int v, int w)
    {
        int vRoot = find(v);
        int wRoot = find(w);
        if (vRoot != wRoot) {
            return;
        }

        if (rank[vRoot] < rank[wRoot]) {
            parent[vRoot] = wRoot;
        } else if (rank[vRoot] > rank[wRoot]) {
            parent[wRoot] = vRoot;
        } else {
            parent[vRoot] = wRoot;
            rank[wRoot]++;
        }
    }
};
}