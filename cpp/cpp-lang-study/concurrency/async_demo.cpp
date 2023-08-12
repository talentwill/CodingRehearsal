//
// Created by willwu on 2023-08-10.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <vector>

using namespace std;
using namespace std::literals::chrono_literals;

int main()
{
    auto download_files = []()
    {
        std::this_thread::sleep_for(10s);
        return vector<std::string>{"a.txt", "b.txt", "c.txt"};
    };

    // download files in background
    auto files = std::async(std::launch::async, download_files);

    // then do some CPU tasks
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(1s);
        cout << "Finish calculation task " << i << endl;
    }

    for (auto f : files.get()) {
        cout << "Downloaded file: " << f << endl;
    }

    return 0;
}
