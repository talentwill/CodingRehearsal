/**
 * @Author: talentwill
 * @Date:   2023-06-10 12:00:43
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-10 12:14:22
 */

#include <iostream>
#include <string>
using namespace std;

/// @brief Implement a sequential queue with a linked list
template <typename T>
struct CircularQueue {

    template <typename U>
    struct ListNode {
        ListNode() { }
        ListNode(U x)
            : val(x)
        {
        }
        U val {};
        ListNode<U>* next = nullptr;
    };

    ListNode<T> head;
    ListNode<T>* tail;

    int n = 0;

    CircularQueue(int capacity)
        : n(capacity)
    {
        tail = &head;
    }

    ~CircularQueue()
    {
        while (head.next) {
            auto p = head.next;
            head.next = p->next;
            delete p;
        }
    }

    bool enqueue(T x)
    {
        tail->next = new ListNode<T>(x);
        tail = tail->next;
        return true;
    }

    T dequeue()
    {
        if (head.next) {
            T ret = head.next->val;
            head.next = head.next->next;
            return ret;
        }
        return {};
    }
};

int main(int argc, char const* argv[])
{
    CircularQueue<int> aq(10);
    for (int i = 0; i < 10; i++) {
        aq.enqueue(i);
    }

    for (int i = 0; i < 11; i++) {
        std::cout << aq.dequeue();
    }

    return 0;
}