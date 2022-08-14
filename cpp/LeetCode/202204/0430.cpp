#include "../helper.h"

class Solution {
public:
    int strToInt1(string str) {
        int sign = 0; // 0 表示符号未知
        int startPos = -1;
        int endPos = -1;

        for (int i = str.find_first_not_of(' '); i < str.size(); i++) {
            char c = str[i];
            if (c == '-' or c == '+') {
                if (sign == 0) {
                    sign = c == '-' ? -1 : 1; // 只判断第一次出现的符号
                }
                else {
                    break;
                }
            }
            else if (c >= '0' and c <= '9') {
                if (sign == 0) {
                    sign = 1;
                }
                if (startPos == -1 and c > '0') {
                    startPos = i;
                }
                endPos = i;
            }
            else {
                break;
            }
        }

        // 没有数字
        if (startPos == -1) {
            return 0;
        }

        // 判断溢出
        int digitCount = endPos - startPos + 1;
        if (digitCount > 10) {
            return sign > 0 ? INT_MAX : INT_MIN;
        }
        else if (digitCount == 10) {
            auto number = str.substr(startPos, digitCount);
            if (sign > 0) {
                if (number >= "2147483647") {
                    return INT_MAX;
                }
            }
            else {
                if (number >= "2147483648") {
                    return INT_MIN;
                }
            }
        }

        int ans = 0;
        for (int i = endPos; i >= startPos; i--) {
            int digit = str[i] - '0';
            ans += (digit * sign);
            sign *= 10;
        }

        return ans;
    }

    int strToInt(string str) {
        int sign = 0;
        int start = str.find_first_not_of(' '); //跳过空格
        if (start != string::npos) {
            char c = str[start];
            if (c == '-' or c == '+' or (c >= '0' and c <= '9')) {
                if (c == '-' or c == '+') {
                    start++; // 数字位后移
                }
                sign = (c == '-') ? -1 : 1; // 符号位判断
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }

        int number = 0;
        for (int i = start; i < str.size(); i++) {
            int x = str[i] - '0';
            if (x >= 0 and x <= 9) {
                if (number > 214748364) {
                    return sign > 0 ? INT_MAX : INT_MIN;
                }
                else if (number == 214748364) {
                    if (sign > 0 and x >= 7) {
                        return INT_MAX;
                    }
                    else if (sign < 0 and x >= 8) { // 增强可读性，没必要统一成 >=7
                        return INT_MIN;
                    }
                }
                number = number * 10 + x;
            }
            else {
                break;
            }
        }
        return sign * number;
    }
};

void test(string str, int ans) {
    if (Solution().strToInt(str) != ans) {
        cout << Solution().strToInt(str) << "!=" << ans << endl;
    }
}

int main(int argc, char const* argv[])
{
    test("-91283472332", INT_MIN);
    test("  0000000000012345678", 12345678);
    test("  003.1400", 3);
    return 0;
}
