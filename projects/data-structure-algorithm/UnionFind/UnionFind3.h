#include <iostream>
#include <string>
#include <vector>
namespace UF3 {

/// @brief Quick Union + 按子树大小优化

class UnionFind3 {
    std::vector<int> parent;
    std::vector<int> size;

public:
    UnionFind3(int n)
    {
        size.resize(n, 1);
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
            // 把小树加到大树上，可以避免子树高度增加
            if (size[vRoot] < size[wRoot]) {
                parent[vRoot] = wRoot;
                size[wRoot] += size[vRoot]; // 大树的size+小树的size
            } else {
                parent[wRoot] = vRoot;
                size[vRoot] += size[wRoot];
            }
        }
    }
};
}