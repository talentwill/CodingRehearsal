/**
 * @Author: talentwill
 * @Date:   2023-06-10 12:00:43
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-10 12:12:54
 */

#include <iostream>
#include <string>
using namespace std;

/// @brief Using array to implement the sequential queue
/// @tparam T
template <typename T>
struct ArrayQueue {
    T* items;
    int n = 0;
    int head = 0;
    int tail = 0;

    ArrayQueue(int capacity)
        : n(capacity)
    {
        items = new T[capacity];
    }

    ~ArrayQueue()
    {
        delete[] items;
    }

    bool enqueue(T x)
    {
        if (tail == n) {
            // Check whether there are free resources
            if (head == 0) {
                return false;
            }
            // Move date to front
            for (int i = head; i < tail; i++) {
                items[i - head] = items[i];
            }
            // Update head and tail pointers
            tail -= head;
            head = 0;
        }

        items[tail++] = x;
        return true;
    }

    T dequeue()
    {
        if (head == tail) {
            return {};
        }
        return items[head++];
    }
};

int main(int argc, char const* argv[])
{
    ArrayQueue<int> aq(10);
    for (int i = 0; i < 10; i++) {
        aq.enqueue(i);
    }

    for (int i = 0; i < 11; i++) {
        std::cout << aq.dequeue();
    }

    return 0;
}
