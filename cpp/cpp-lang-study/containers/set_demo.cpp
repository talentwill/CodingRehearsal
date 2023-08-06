#include <set>
#include <iostream>
using namespace std;

void demo1()
{
    set<int> s0 = {1, 2, 3};

    auto mygreater = [](auto a, auto b)
    {
        return a > b;
    };

    // 定义自己的比较器
    set<int, decltype(mygreater)> gs(mygreater);

    std::copy(s0.begin(), s0.end(), std::inserter(gs, gs.end()));
    for (int x : gs)
    {
        cout << x << ',';
    }
}

int main()
{
    demo1();
    return 0;
}