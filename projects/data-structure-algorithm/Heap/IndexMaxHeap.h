/**
 * @Author: talentwill
 * @Date:   2023-06-11 19:29:30
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-11 21:07:34
 */

#ifndef HEAP_INDEX_MAXHEAP_H
#define HEAP_INDEX_MAXHEAP_H

#include <vector>

using namespace std;

template <typename Item>
class IndexMaxHeap {
    int count_ = 0; // 堆种的元素数量
    int capacity_ = 10; // 堆的最大容量
    vector<Item> data;
    vector<int> indices;
    vector<int> reverse; // 反向索引

public:
    explicit IndexMaxHeap(int capacity)
        : capacity_(capacity)
    {
        // 因为数组索引从1开始，所以空间需要+1
        data.resize(capacity + 1);
        indices.resize(capacity + 1);
        reverse.resize(capacity + 1);
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

    void insert(int index, Item item)
    {
        // if (count_ == capacity_) {
        //     capacity_ *= 2;
        //     data.resize(capacity_ + 1);
        // }
        index++; // Users use index starting from zero.
        data[index] = item;

        count_++;
        indices[count_] = index;
        reverse[index] = count_;

        shift_up(count_);
    }

    Item popMax()
    {
        auto ret = data[indices[1]];
        indices[1] = indices[count_--];

        reverse[indices[1]] = 1;
        reverse[indices[count_]] = 0; // remove it.

        shift_down(1);
        return ret;
    }

    int popMaxIndex()
    {
        auto ret = indices[1] - 1;
        indices[1] = indices[count_--];

        reverse[indices[1]] = 1;
        reverse[indices[count_]] = 0; // remove it.

        shift_down(1);
        return ret;
    }

    Item get_item(int index)
    {
        if (not contain(index)) {
            return {};
        }
        return data[index + 1];
    }

    bool contain(int index)
    {
        index++;
        // 因为整个索引堆的id范围是0-capacity的值
        if (index >= 0 and index <= capacity_) {
            return reverse[index] != 0;
        }
        return false;
    }

    void change(int index, Item new_item)
    {
        if (not contain(index)) {
            return;
        }

        index++;
        data[index] = new_item;
        // for (int i = 1; i <= count_; i++) {
        //     if (i == indices[index]) {
        //         shift_up(i);
        //         shift_down(i);
        //         return;
        //     }
        // }
        int j = reverse[index];
        shift_up(j);
        shift_down(j);
    }

private:
    void shift_up(int k)
    {
        // 1. the root is 1, so if k <= 1, means all the items are compared
        // if k is larger then k's parent, swap k and k's parent.
        while (k > 1 and data[indices[k]] > data[indices[k / 2]]) {
            swap(indices[k], indices[k / 2]);
            reverse[indices[k]] = k;
            reverse[indices[k / 2]] = k / 2;
            k /= 2;
        }
    }
    void shift_down(int k)
    {
        // if k has left child
        while (k * 2 <= count_) {
            int j = 2 * k;
            if (j + 1 <= count_ and data[indices[j + 1]] > data[indices[j]]) {
                j = j + 1;
            }
            if (data[indices[k]] >= data[indices[j]]) {
                break;
            }
            swap(indices[k], indices[j]);
            reverse[indices[k]] = k;
            reverse[indices[j]] = j;
            k = j;
        }
    }
};

#endif // HEAP_INDEX_MAXHEAP_H
