#include <iostream>
#include <string>
#include <vector>
namespace UF6 {

/// @brief Quick Union + 路径压缩递归版，路径所有节点指向根

class UnionFind6 {
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind6(int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // 路径压缩终极版，所有路径上的节点都指向根节点
    // 但是由于存在递归，性能不绝对比两步压缩好。
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
            return;
        }
        // 仍然保留按秩优化
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