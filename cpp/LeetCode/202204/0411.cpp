#include "../helper.h"

class Solution1 {
public:
    int nthUglyNumber(int n) {
        set<long> seen = {1}; //使用 std::set 即可以排序也可以去重，long防止溢出
        int ugly = 1;
        for (size_t i = 0; i < n; i++) {
            auto m = *seen.begin(); // 取出最小的丑数
            
            // 添加丑数衍生出来的丑数，去重并排序
            seen.insert(m * 2);
            seen.insert(m * 3);
            seen.insert(m * 5);

            ugly = *seen.begin(); // 获取第i个丑数
            seen.erase(seen.begin()); // 移除
        }
        
        return ugly;
    }
};

class Solution2 {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for (size_t i = 1; i < n; i++) {
            int n2 = dp[p2] * 2, n3 = dp[p3] * 3, n5 = dp[p5] * 5;
            dp[i] = min(min(n2,n3), n5); // 得到最小的丑数
            if (n2 == dp[i]) p2++;
            if (n3 == dp[i]) p3++;
            if (n5 == dp[i]) p5++;
        }
        return dp[n-1];
    }
};


int main()
{
    int n = 1690;
    cout << "\n" << Solution1().nthUglyNumber(n);
    cout << "\n" << Solution2().nthUglyNumber(n);
    return 0;
}