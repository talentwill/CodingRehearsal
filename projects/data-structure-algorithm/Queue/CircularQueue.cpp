/**
 * @Author: talentwill
 * @Date:   2023-06-10 12:00:43
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-10 12:13:46
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// @brief Implement a circular queue with an array
template <typename T>
struct CircularQueue {
    int n = 0;
    int head = 0;
    int tail = 0;
    vector<T> items;

    CircularQueue(int capacity)
        : n(capacity + 1) // N+1 is because there is a space in the circular queue that cannot be used
    {
        items.resize(n);
    }

    bool enqueue(T x)
    {
        if ((tail + 1) % n == head) {
            return false;
        }
        items[tail++] = x;
        return true;
    }

    T dequeue()
    {
        if (tail == head) {
            return {};
        }
        return items[head++];
    }
};

int main(int argc, char const* argv[])
{
    CircularQueue<int> aq(10);
    for (int i = 0; i < 10; i++) {
        aq.enqueue(i);
    }

    for (int i = 0; i < 10; i++) {
        std::cout << aq.dequeue();
    }

    return 0;
}