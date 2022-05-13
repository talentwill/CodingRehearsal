#include "../helper.h"


struct MaxQueue {

    MaxQueue() {
        push_back(1);
        push_back(2);
        cout << max_value();
        cout << pop_front();
        cout << max_value();
    }

    deque<int> data_queue;
    deque<int> max_queue;

    int pop_front() {
        if (data_queue.empty()) {
            return -1;
        }

        int front = data_queue.front();
        data_queue.pop_front();

        if (front == max_queue.front()) {
            max_queue.pop_front();
        }

        return front;
    }

    void push_back(int value) {
        data_queue.push_back(value);

        while (not max_queue.empty() and max_queue.back() < value) {
            max_queue.pop_back();
        }
        max_queue.push_back(value);
    }

    int max_value() {
        if (max_queue.empty()) {
            return -1;
        }
        return max_queue.back();
    }
};


int main(int argc, char const* argv[])
{
    MaxQueue();
    return 0;
}

/*


我们只需记住当前最大值出队后，队列里的下一个最大值即可。

Let's choose a deque for storing max values. when


*/