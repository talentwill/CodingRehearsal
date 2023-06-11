/**
 * @Author: talentwill
 * @Date:   2023-1-28 08:00:00
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-10 15:45:36
 */

#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H

#include <vector>

using namespace std;

template <typename Item>
class IndexMaxHeap {
    int count_ = 0; // 堆种的元素数量
    int capacity_ = 10; // 堆的最大容量
    vector<Item> data;

public:
    explicit IndexMaxHeap(int capacity)
        : capacity_(capacity)
    {
        // 因为数组索引从1开始，所以空间需要+1
        data.resize(capacity + 1);
    }
    /// @brief Get the count of the heap
    /// @return count
    int size()
    {
        // becase the array starts at 1, count is the size.
        return count_;
    }

    bool empty()
    {
        return count_ == 0;
    }

    void insert(Item item)
    {
        if (count_ == capacity_) {
            capacity_ *= 2;
            data.resize(capacity_ + 1);
        }
        data[++count_] = item;
        shift_up(count_);
    }

    Item popMax()
    {
        auto ret = data[1];
        data[1] = data[count_--];
        shift_down(1);
        return ret;
    }

private:
    void shift_up(int k)
    {
        // 1. the root is 1, so if k <= 1, means all the items are compared
        // if k is larger then k's parent, swap k and k's parent.
        while (k > 1 and data[k] > data[k / 2]) {
            swap(data[k], data[k / 2]);
            k /= 2;
        }
    }
    void shift_down(int k)
    {
        // if k has left child
        while (k * 2 <= count_) {
            int j = 2 * k;
            if (j + 1 <= count_ and data[j + 1] > data[j]) {
                j = j + 1;
            }
            if (data[k] >= data[j]) {
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }
};

#endif // HEAP_MAXHEAP_H
