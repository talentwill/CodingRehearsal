#include "../helper.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int x = nums[mid];
            if (x >= target) {
                right = mid - 1;
            } else if (x < target) {
                left = mid + 1;
            }
        }

        cout << nums[right];

        int low = 0;
        int high = right;
        while (low <= high) {
            int sum = nums[low] + nums[high];
            if (sum > target) {
                high--;
            } else if (sum < target) {
                low++;
            } else {
                return {nums[low], nums[high]};
            }
        }

        return {};
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3, 6, 9, 19, 39, 49,88, 98};
    auto ans = Solution().twoSum(nums, 25);
    return 0;
}
