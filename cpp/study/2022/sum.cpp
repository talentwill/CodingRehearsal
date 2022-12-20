#include <iostream>
using namespace std;

int main() 
{
    int n = 0;
    int sum = 0;
    while (sum < 1000)
    {
        n += 1;
        sum += n;
    }
    cout << n;
    return 0;    
}

#include <iostream>
#include <iomanip> // 精确到小数点的位数的函数库
using namespace std;

int main1()
{
    double pi = 0; // 双精度浮点数类型，PI
    int sign = 1; // 符号位
    int n = 1;
    while (1.0 / n > 1e-8) // 1e-8， 10的负8次方=0.00000001
    {
        pi += (1.0 / n) * sign; // 累加Pi, 轮流加减变成累加形式（减去一个数，转成加上一个负数）

        // 更新下一轮用的参数
        sign *= -1; // 1. 变换正负号
        n += 2;     // 2. n加2
    }
    cout << fixed << setprecision(10) << pi * 4;
    return 0;
}