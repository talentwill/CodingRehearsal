#include "../helper.h"

class MagicDictionary {
public:
    struct TrieNode {
        map<char, TrieNode *> children;
        bool isEnd = false;

        TrieNode *child(char c) {
            if (children.find(c) == children.end()) {
                children[c] = new TrieNode();
            }
            return children[c];
        }
    } root;

    void buildDict(vector<string> dictionary) {
        for (auto word: dictionary) {
            TrieNode *node = &root;
            for (auto c: word) {
                node = node->child(c);
            }
            node->isEnd = true;
        }
    }

    // index 待比较的字符索引，从0开始计算，editCount记录已经修改的次数
    bool dfs(TrieNode *node, string word, int index, int editCount) {
        // index达到size，说明字符已经全部匹配完毕
        // 检查当前的node是否是完整的单词，并且edit必须等于1
        if (index == word.size() && node->isEnd && editCount == 1) {
            return true;
        }

        // 只有当edit次数2次，才继续比较剩余的字符
        if (editCount <= 1 && index < word.size()) {
            char c = word[index];
            for (auto [k, v]: node->children) {
                // 当前字符不等于节点的值，edit+1，表示这个节点不匹配了，继续比较下一个节点
                if (dfs(v, word, index + 1, c != k ? editCount + 1 : editCount)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(string searchWord) {
        return dfs(&root, searchWord, 0, 0);
    }
};

class Solution {
public:

    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        std::map<int, int> counts;
        for (auto x: arr1) {
            counts[x]++;
        }
        int i = 0;
        for (auto num: arr2) {
            while (counts[num]-- > 0) {
                arr1[i++] = num;
            }
        }

        for (auto &[k, v]: counts) {
            while (v-- > 0) {
                arr1[i++] = k;
            }
        }
        return arr1;
    }

    vector<int> relativeSortArray2(vector<int> &arr1, vector<int> &arr2) {
        // 1. 利用算法找出最小最大值
        auto [minNum, maxNum] = std::minmax_element(arr1.begin(), arr1.end());

        // 2. 计数排序
        vector<int> bucket(*maxNum - *minNum + 1);
        for (auto x: arr1) {
            bucket[x - *minNum]++;
        }

        // 3. 根据arr2的顺序排序
        vector<int> res;
        for (auto x: arr2) {
            while (bucket[x - *minNum]-- > 0) {
                res.emplace_back(x);
            }
        }

        // 4. 把剩余的元素排序
        for (int i = 0; i < bucket.size(); i++) {
            while (bucket[i]-- > 0) {
                res.emplace_back(i + *minNum);
            }
        }
        return res;
    }
};

// sort from small to big
struct QuickSort {
    // 把区间分成两块区域，左边的元素都小于右边都元素
    int partition(vector<int> &nums, int start, int end) {
        int small = start - 1; // 表示数组前半部分游标
        swap(nums[start], nums[end]); // 选择第一个元素作为分界数，并挪动到最后
        // 循环查找比分界数小的数字，交换到数字到前半部分
        for (int i = start; i < end; i++) {
            if (nums[i] < nums[end]) {
                // 游标加1，让小元素加入到左边分区
                swap(nums[++small], nums[i]);
            }
        }
        // 最后，需要分界数交换回来
        swap(nums[++small], nums[end]);
        return small;
    }

    void quickSort(vector<int> &nums, int start, int end) {
        if (start < end) {
            int pivot = partition(nums, start, end); // 分区
            quickSort(nums, start, pivot - 1);  // 递归左分区
            quickSort(nums, pivot + 1, end);   // 递归右分区
        }
    }

    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

struct Solution1 {
    int partition(vector<int> &nums, int start, int end) {
        int small = start - 1;
        swap(nums[start], nums[end]);
        for (int i = start; i < end; i++) {
            if (nums[i] > nums[end]) {
                swap(nums[++small], nums[i]);
            }
        }
        swap(nums[++small], nums[end]);
        return small;
    }

    int findKthLargest(vector<int> &&nums, int k) {
        k = k - 1;
        int start = 0;
        int end = nums.size() - 1;
        int index = -1;
        while (index != k) {
            index = partition(nums, start, end);
            if (index < k) {
                start = index + 1;
            } else if (index > k) {
                end = index - 1;
            }
        }
        return nums[k];
    }
};

TEST(hello, case1) {
    EXPECT_EQ(2, Solution1().findKthLargest({-1, 2, 0}, 1));
}

int main1(int argc, char const *argv[]) {
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    // Solution().relativeSortArray(arr1, arr2);

    // QuickSort().findK(arr1, 3);
    cout << Solution1().findKthLargest({-1, 2, 0}, 1);
    return 0;
}
