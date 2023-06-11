/**
 * @Author: talentwill
 * @Date:   2023-06-10 08:00:00
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-11 21:00:45
 */
#include <vector>
using namespace std;

template <typename T>
void heap_sort(vector<T>& v)
{
    auto shift_down = [&v](int n, int k) {
        // 左孩子不越界，n取不到
        while (k * 2 + 1 < n) {
            int j = k * 2 + 1;
            // 右孩子大还是左孩子大？
            if (j + 1 < n and v[j + 1] > v[j]) {
                j += 1;
            }
            // 父节点比两个孩子都大，无需调整
            if (v[k] >= v[j]) {
                break;
            }
            swap(v[k], v[j]);
            k = j;
        }
    };
    int n = v.size();

    // 1. 原地构造最大堆
    // 完全二叉树从0开始存元素，因此，最后一个非叶子节点i=(n-1)/2
    // 从后往前不断调整，直到root的索引0调整完毕
    for (int i = (n - 1) / 2; i >= 0; i--) {
        shift_down(n, i);
    }

    // 2. 把堆顶和尾部元素交换
    // 堆顶元素往下调整，同时堆的大小不断缩小
    for (int i = (n - 1); i > 0; i--) {
        swap(v[0], v[i]);
        shift_down(i, 0);
    }
}