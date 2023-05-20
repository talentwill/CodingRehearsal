#include <iostream>
#include <string>
#include <vector>

namespace UF2 {

/// @brief Quick Union 版本

class UnionFind2 {
    std::vector<int> parent;

public:
    UnionFind2(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v)
    {
        if (parent[v] != v) {
            return find(parent[v]);
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
            parent[vRoot] = wRoot;
        }
    }
};
}