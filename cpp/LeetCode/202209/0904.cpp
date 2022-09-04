#include "../helper.h"

// 单调栈算法，递增的栈
class Solution38 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1); // 辅助用的左边界，下标为-1.

        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            // 把栈内更高的柱子出栈，并计算以该柱子为顶的矩形的面积。
            while (s.size() > 1 && (heights[i] < heights[s.top()])) {
                int j = s.top(); s.pop(); // 高柱子出栈
                // 单调递增栈，栈顶的元素，一定是比这个高柱子矮的
                // 出栈的高柱子，左右两边矮的柱子的下标之差，就是这个矩形的长
                area = max(heights[j] * (i - s.top() - 1), area); 
            }
            s.push(i);
        }
        
        // 剩余的部分，全是单调递增的柱子，右边的边界就说heights.size()
        while (s.size() > 1) {
            int h = heights[s.top()];
            s.pop();
            int len = heights.size() - s.top() - 1;
            area = max(area, h * len);
        }
        return area;
    }
};

// 这里会超出时间限制，使用分治算法
// 找出区间中，最矮的柱子，计算区间长度*最矮柱子的高。
// 递归左右两边的柱子，最后治之。
class Solution38v2 {
public:
    int largestRectangleArea11(vector<int>& heights) {
        return helper(heights, 0, heights.size() - 1);
    }
    
    int helper(vector<int>& heights, int start, int end) {
        if (start > end) {
            return 0;
        }

        if (start == end) { // 区间只有一个元素
            return heights[start];
        }

        int minIndex = start; // 最矮的柱子的下标
        for (int i = start; i <= end; i++) {
            if (heights[i] < heights[minIndex]) {
                minIndex = i;
            }
        }
        // 本区间以最矮的柱子为高度，矩形的面积。
        int area = heights[minIndex] * (end - start + 1);

        int areaLeft = helper(heights, start, minIndex - 1);
        int areaRight = helper(heights, minIndex + 1, end);
        return max(area, max(areaLeft, areaRight));
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (s.size() > 1 && heights[i] < heights[s.top()]) {
                int h = heights[s.top()]; s.pop();
                int w = i - s.top() - 1;
                area = max(area, h * w);
            }
            s.push(i);
        }

        while (s.size() > 1) {
            int h = heights[s.top()]; s.pop();
            int w = heights.size() - s.top() - 1;
            area = max(area, h * w);
        }
        return area;
    }
};

void case1()
{
    Solution38 s1;
    Solution38v2 s2;
    vector<int> v = { 2, 1, 2 };
    cout << s1.largestRectangleArea(v) << "=" << s2.largestRectangleArea(v);
}

void case2()
{
    Solution38 s1;
    Solution38v2 s2;
    vector<int> v = { 3,1,3,2,2 };
    cout << s1.largestRectangleArea(v) << "=" << s2.largestRectangleArea(v);
}

int main()
{
    case1();
    return 0;
}
