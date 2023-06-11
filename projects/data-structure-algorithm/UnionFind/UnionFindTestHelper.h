#pragma once

#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"
#include "UnionFind6.h"
#include <ctime>
#include <iostream>

using namespace std;

struct Timer {
    time_t start_time = clock();
    double elapsed()
    {
        return double(clock() - start_time) / CLOCKS_PER_SEC;
    }
};

namespace UnionFindTestHelper {

auto seed = time(nullptr);

template <typename T>
void testUnionFind(int n, string name)
{
    srand(seed);
    Timer t;
    T uf(n);
    for (int i = 0; i < n; i++) {
        int v = rand() % n;
        int w = rand() % n;
        uf.unionElements(v, w);
    }
    for (int i = 0; i < n; i++) {
        int v = rand() % n;
        int w = rand() % n;
        uf.isConnected(v, w);
    }
    cout << name << ": " << 2 * n << " ops, " << t.elapsed() << "s.\n";
}

}