/**
 * @Author: talentwill
 * @Date:   2023-06-10 08:00:00
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-10 15:37:54
 */
#include "HeapSort.h"
#include "MaxHeap.h"
#include <ctime>
#include <iostream>

int main()
{
    srand(time(0));
    // MaxHeap<int> mh(100);
    // for (int i = 0; i < 50; i++) {
    //     mh.insert(rand() % 100);
    // }

    // while (not mh.empty()) {
    //     cout << mh.popMax() << ",";
    // }

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.emplace_back(rand() % 100);
    }
    heap_sort(v);
    for (int i = 0; i < 10; i++) {
        cout << v[i] << ",";
    }

    return 0;
}
