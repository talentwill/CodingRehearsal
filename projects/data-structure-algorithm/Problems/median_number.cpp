/**
 * @Author: talentwill
 * @Date:   2023-06-23 00:03:13
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-23 01:08:10
 */
#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 数据流中的中位数，使用两个堆来实现
class MedianNumber {
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int> maxHeap;

public:
    // 插入一个数
    void insert(int x)
    {
        if (maxHeap.empty()) {
            maxHeap.emplace(x);
            return;
        }

        if (x <= maxHeap.top()) {
            maxHeap.emplace(x);
        } else {
            minHeap.emplace(x);
        }

        // 调整两个堆的大小，保证最大堆的大小最多比最小堆大1
        while (maxHeap.size() > minHeap.size() and maxHeap.size() - minHeap.size() > 1) {
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        }
        // 调整两个堆的大小，小顶堆的大小不能比大顶堆大
        while (minHeap.size() > maxHeap.size() and minHeap.size() - maxHeap.size() > 0) {
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }
    // 返回中位数
    int result()
    {
        return maxHeap.top();
    }
};

int main(int argc, char const* argv[])
{
    srand(time(0));
    int n = 100;

    MedianNumber mn;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x = rand() % n;

        // 先把数组保存到vector中，然后排序，再取中位数
        v.emplace_back(x);
        sort(v.begin(), v.end());

        // 插入到中位数数据结构中
        mn.insert(x);

        int expect = v[ceil(v.size() / 2.0) - 1]; // 规律通过观察得出
        assert(mn.result() == expect);
    }

    return 0;
}
