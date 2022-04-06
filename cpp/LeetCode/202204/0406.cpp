#include "../helper.h"

// Offer 31. 栈的压入、弹出序列
class Solution31 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty()) {
            return true;
        }

        int top = -1;
        vector<int> stack(pushed.size());

        int j = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            stack[++top] = pushed[i];
            while (top >= 0 and stack[top] == popped[j])
            {
                j++;
                top--;
            }
        }

        return j == popped.size();
    }
};

void Solution31_test() {
    cout << endl  << __func__ << endl;
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {4,5,3,2,1}; // OK
    vector<int> v3 = {4,3,5,1,2}; // NOK
    cout << Solution31().validateStackSequences(v1, v3);
}

// Offer 34. 二叉树中和为某一值的路径
class Solution34 {
public:
 vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> sum;
        dfs(root, target, sum);
        return ans;
    }

    void dfs(TreeNode* node, int target, vector<int>& sum) {
        if (node != nullptr) {
            sum.emplace_back(node->val);
            if (node->left == nullptr and node->right == nullptr and node->val == target) {
                ans.emplace_back(sum);
            }
            else {
                dfs(node->left, target - node->val, sum);
                dfs(node->right, target - node->val, sum);
            }
            sum.pop_back();
        }
    }

    vector<vector<int>> ans;
};


// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：[[5,4,11,2],[5,8,4,5]]
void Solution34_test1() {
    cout << endl  << __func__ << endl;
    auto root = createTree({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1});
    printTree(root);
    print2DVectors(Solution34().pathSum(root, 22));
}

// 输入：root = [1,2,3], targetSum = 5
// 输出：[]
void Solution34_test2() {
    cout << endl  << __func__ << endl;
    auto root = createTree({1,2,3});
    printTree(root);
    print2DVectors(Solution34().pathSum(root, 5));
}

// [1,2,null,3,null,4,null,5] = 6,[]
void Solution34_test3() {
    cout << endl  << __func__ << endl;
    auto root = createTree({1, 2, null, 3, null, 4, null, 5});
    printTree(root);
    print2DVectors(Solution34().pathSum(root, 6));
}

/* cases
[5,4,8,11,null,13,4,7,2,null,null,5,1]
22

[1,2]
1

[1]
1

[-2, null, -3]
-5

[1,2,null,3,null,4,null,5]
6
*/

int main() {
    Solution31_test();
    Solution34_test1();
    Solution34_test2();
    Solution34_test3();
    return 0;
}