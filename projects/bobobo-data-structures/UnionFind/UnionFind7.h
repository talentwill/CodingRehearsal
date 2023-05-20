#include <vector>

/// @brief 路径压缩优化，代码简单，适合刷题
struct UnionFind {
    std::vector<int> parent;
    int count = 0;
    UnionFind(int n)
        : count(n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v)
    {
        if (v != parent[v]) {
            v = find(parent[v]);
        }
        return parent[v];
    }

    void unionElements(int v, int w)
    {
        int vv = find(v), ww = find(w);
        if (vv != ww) {
            parent[vv] = ww; // Quick Union 合并只用一次赋值
            count--;
        }
    }
};

/// @brief 路径压缩优化 + 子树大小优化，效率稍微提高一点
struct UnionFind {
    std::vector<int> parent, sz;
    int count = 0;
    UnionFind(int n)
    {
        count = n;
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v)
    {
        if (v != parent[v]) {
            v = find(parent[v]);
        }
        return parent[v];
    }

    bool isConnected(int v, int w)
    {
        return find(v) == find(w);
    }

    void unionElements(int v, int w)
    {
        int vv = find(v), ww = find(w);
        if (vv != ww) {
            if (sz[vv] < sz[ww]) {
                parent[vv] = ww;
                sz[ww] += sz[vv];
            } else {
                parent[ww] = vv;
                sz[vv] += sz[ww];
            }
            count--;
        }
    }
};
