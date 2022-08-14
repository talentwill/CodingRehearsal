#include <iostream>
#include <vector>

using namespace std;

struct Person
{
    Person(int a = 0) { age = a; }
    int age = 0;
};

// 测试vector的其中一个元素的引用，会随着vector的扩容之后，失效的问题。
// 但是，在Rust中，他强制一个vector如果存在引用，则无法进行对其的修改操作了。
// 测试发现，C++确实存在这个隐患！！
int main(int argc, char const* argv[])
{
    vector<Person> v2;
    for (int i = 0; i < 10; i++) {
        v2.emplace_back(i + 100);
    }

    Person& p1 = v2[0];  // 1. 取得对vector第一个原色的引用
    cout << "p1=" << p1.age << "\n";

    for (int i = 0; i < 100; i++) { // 2. 不断增加vector的元素
        v2.emplace_back(i);
        if (p1.age != v2[0].age) {  // 3. 因为vector容量不够的时候，会扩容一倍，导致原来的引用变量失效。
            cout << "i=" << i << ", p1.age=" << p1.age << endl;
            break;
        }
    }
    return 0;
}
