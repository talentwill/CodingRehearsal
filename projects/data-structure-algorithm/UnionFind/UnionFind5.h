#include <iostream>
#include <string>
#include <vector>

namespace UF5 {

/// @brief Quick Union + 路径压缩迭代版本，两步合并

class UnionFind5 {
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind5(int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v)
    {
        // 路径压缩，两步一跳，子树的高度-1，
        while (v != parent[v]) {
            v = parent[parent[v]]; // v 指向父亲的父亲
        }
        return v;
    }

    bool isConnected(int v, int w)
    {
        return find(v) == find(w);
    }

    // 路径压缩 + 按秩合并
    void unionElements(int v, int w)
    {
        int vRoot = find(v);
        int wRoot = find(w);
        if (vRoot != wRoot) {
            return;
        }
        // 路径压缩之后，Rank已经无法表示真实的height
        // 因为两颗子树都压缩了，仍然可以用来比较优化，可以小幅度提升
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