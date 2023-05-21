#include <array>
#include <iostream>

/// @brief 测试 constexpr 对象的用法
void constexpr_object()
{
    int a = 10;
    // constexpr int ca = a; // error, ca 无法在编译期确定，因为a不是常量

    const int ca = a; // ca 是一个常量，但是并非编译阶段确定的，仅代表ca的值不能被修改
    // std::array<int, ca> arr1; // error, ca无法用于整形常量表达式语境

    // constexpr int cb = ca; // error, cb 明确要求必须是编译器常量，但ca 只是常量

    constexpr auto c = 10; // ok，10 是编译器常量
    std::array<int, c> data; // ok，可以用于整形常量表达式语境
}

/// @brief 声明一个 constexpr 函数，支持编译期计算结果
constexpr auto pow(int base, int exp) noexcept
{
    auto result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
        // std::cout << result; // 添加IO语句，导致函数声明中的constexpr失效
    }
    return result;
}

/// @brief 测试 constexpr 函数的用法
auto constexpr_function()
{
    constexpr auto exp1 = 5;
    std::array<int, pow(3, exp1)> arr1; // pow(3, 5) 的结果在编译期就计算好，不需要真正运行这个函数

    auto exp2 = 5;
    auto ret = pow(3, exp2); // 虽然exp2不是常量，不过pow的值会在运行期间计算

    // std::array<int, pow(3, exp2)> arr2; //  error, array的size无法在编译期间确定
}

auto constexpr_lambda_expression()
{
    // lambda 天然支持constexpr，不需要显式声明
    auto pow1 = [](int base, int exp) noexcept {
        auto result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    };
    constexpr auto exp1 = 5;
    std::array<int, pow1(3, exp1)> arr1;
}

// TODO: 添加 constexpr 用户自定义类
struct Point {
    int x;
    int y;
};

int main(int argc, char const* argv[])
{
    constexpr_object();
    constexpr_function();
    constexpr_lambda_expression();
    return 0;
}
