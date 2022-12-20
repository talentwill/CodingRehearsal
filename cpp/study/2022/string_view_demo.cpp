#include <iostream>
#include <string_view>

using namespace std;

std::string_view hello = "this is a string view";

void print0(string_view str)
{
    for (auto c : str) {
        cout << c;
    }
}

void print1(const string& str)
{
    for (auto c : str) {
        cout << c;
    }
}

void substr(string_view str)
{
    auto sub = str.substr(1, 2);
    cout << sub;
}

void substr1()
{
    auto s1 = "hello"s;
    string_view sv = s1;
    auto sub = sv.substr(1, 2);
    // cout << sub;
    // s1[1] = '?';
    // s1[2] = '?';
    auto s2 = "aaa"s;
    s1 = "may";
    s1.swap(s2);

    cout << sub;
}

int main()
{
    // print(hello);
    substr1();
    return 0;
}