#include "../helper.h"

double quickMul(double x, int n) {
    if (n == 0) {
        return 1;
    }

    auto y = quickMul(x, n / 2);
    if (n % 2 == 1) {
        return y * y * x;
    }
    return y * y;
}

double quickMul2(double x, int n) {
    bitset<32> bin(n);
    auto count = bin.count();
    double ans = 1, mul = x;
    for (size_t i = 0; i < bin.size() and count > 0; i++) {
        if (bin.test(i)) {
            ans *= mul;
            count--;
        }
        mul *= mul;
    }
    return ans;
}

double quickMul3(double x, int n) {
    double ans = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            ans *= x;
        }
        x *= x;
        n /= 2;
    }
    return ans;
}

double myPow(double x, int n)
{
    if (n < 0) {
        return 1 / quickMul3(x, -n);
    }
    else {
        return quickMul3(x, n);
    }
}

void testPow(double x, int n) {
    cout << myPow(x, n) << " == " << std::pow(x, n) << endl;
}

int main(int argc, char const* argv[])
{
    testPow(4, 9);
    // quickMul2(1, 9);
    return 0;
}