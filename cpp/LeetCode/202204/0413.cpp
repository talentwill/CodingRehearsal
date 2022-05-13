#include "../helper.h"

// 减绳子

class Solution1
{
public:
    int cuttingRope(int n) {
        vector<int> products = { 0, 1, 2, 3 };
        products.resize(n + 1);
        int ans = 0;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                ans = max(ans, products[j] * products[i - j]);
            }
            products[i] = ans;
        }
        return products[n];
    }
};

class Solution2 {
public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n - 1;

        int quotient = n / 3;·
        int remainder = n % 3;

        if (remainder == 0) { // 整除
            remainder = 1;
        }
        else if (remainder == 1) { // 余1，把 3+1 变成 2+2
            remainder = 4;
            quotient--; //
        }
        long res = remainder;
        for (int i = 0; i < quotient; i++) {
            res = (res * 3) % 1000000007;
        }
        return res;
    }
};

int main() {
    cout << Solution2().cuttingRope(10);
    return 0;
}
// 剑指 Offer 44. 数字序列中某一位的数字

class Solution {
public:

    int countOfInteger(int digits) {
        return 9 * std::pow(10, digits - 1);
    }

    int findNthDigit(int n) {
        if (n <= 9) return n;

        int digit = 1;
        int start = 1;
        int count = 10;
        while (n > count) {
            n -= count;
            start *= 10;
            digit++;
            count = countOfInteger(digit) * digit;
        }

        int num = start + n / digit;
        return std::to_string(num).at(n %digit) - '0';
    }
};


int main() {

    cout << Solution().findNthDigit(12);
    return 0;
}
