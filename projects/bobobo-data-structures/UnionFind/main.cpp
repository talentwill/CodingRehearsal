#include "UnionFindTestHelper.h"

using namespace UnionFindTestHelper;

int main(int argc, char const* argv[])
{
    int n = 1000000;
    testUnionFind<UF1::UnionFind1>(n, "UF1");
    testUnionFind<UF2::UnionFind2>(n, "UF2");
    testUnionFind<UF3::UnionFind3>(n, "UF3");
    testUnionFind<UF4::UnionFind4>(n, "UF4");
    testUnionFind<UF5::UnionFind5>(n, "UF5");
    testUnionFind<UF6::UnionFind6>(n, "UF6");

    return 0;
}
