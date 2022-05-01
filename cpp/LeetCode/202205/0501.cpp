#include "../helper.h"

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<int> counts(6 * n + 1, 0);

        for (int i = 1; i <= 6; i++) {
            counts[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            vector<int> temp(6 * n + 1, 0);
            for (int j = i; j <= i * 6; j++) {
                for (int k = 1; k <= 6; k++) {
                    temp[j + k] = counts[j];
                }
            }
            counts = temp;
        }

        vector<double> ans;
        double p = pow(1.0 / 6, n);
        for (int i = n; i < counts.size(); i++) {
            ans.emplace_back(counts[i] * p);
        }

        return ans;
    }
};


class Solution1 {
public:
    int singleNumber1(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (auto x : nums) {
            counts[x] += 1;
        }
        for (auto [k, v] : counts) {
            if (v == 1) {
                return k;
            }
        }
        return -1;
    }

    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        for (auto x : nums) {
            int i = 0;
            while (x > 0) {
                bits[i++] += x & 1;
                x = x >> 1;
            }
        }

        int ans = 0;
        for (int i = bits.size() - 1; i >= 0; i--) {
            ans = ans << 1;
            ans |= bits[i] % 3;
        }

        return ans;
    }
};


int main() {
    // Solution().dicesProbability(2);
    vector<int> n = { 3,4,4,4 };
    Solution1().singleNumber(n);
    return 0;
}