#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;
using namespace std::literals::chrono_literals;

int thread1_task()
{
    cout << "thread-1 start:\n";
    std::this_thread::sleep_for(10s);
    cout << "thread-1 exit:\n";
    return 1;
}

int main()
{
    std::thread t1(thread1_task);
    std::thread t2([&]() {
        cout << "thread-2 start:\n";
        t1.join(); // t2 wait for t1
        cout << "thread-2 exit:\n"; 
    });

    t2.join(); // main wait for t2

    return 0;
}
