#include "../helper.h"

// 把数字翻译成字符串
struct Offer46
{
    Offer46() {
        cout << translateNum(25);
    }

    int translateNum(int num) {
        if (num < 10) {
            return 1;
        }

        string str = to_string(num);

        int p1 = 1;
        int p2 = 1;
        int fi = 0;
        for (int i = 1; i < str.size(); i++) {
            fi = p1;
            if (i >= 1) {
                auto temp = str.substr(i - 1, 2);
                if (temp >= "10" and temp <= "26") {
                    fi += p2;
                }
            }
            p2 = p1;
            p1 = fi;
        }

        return fi;
    }
};

// 数据流中的中位数
struct Offer41
{
    Offer41() {
        //test();
        find();
    }

    void test() {
        priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆

        c.push(1);
        c.push(7);
        c.push(14);
        c.push(11);
        c.push(13);
        c.push(61);

        for (int i = 0; i < 6; i++) {
            cout << c.top() << " size=" << c.size()<<", ";
            c.pop();
        }
    }

    void find() {

        addNum(1);
        addNum(7);
        addNum(14);
        addNum(11);
        addNum(13);
        addNum(61);
        findMedian();
    }

    priority_queue<int, vector<int>, greater<int> > cs; 
    priority_queue<int, vector<int>, less<int> > cb;

    void addNum(int num) {
        if (!cs.empty() and num >= cs.top()) {
            cs.push(num);
        }
        else if (!cb.empty() and num <= cb.top()) {
            cb.push(num);
        }
        else {
            if (cs.size() > cb.size()) {
                cb.push(num);
            }
            else {
                cs.push(num);
            }
        }
    }

    double findMedian() {
        while (int(cb.size() - cs.size()) > 1) {
            cs.push(cb.top());
            cb.pop();
        }

        while (int(cs.size() - cb.size()) > 1) {
            cb.push(cs.top());
            cs.pop();
        }

        if (cb.size() == cs.size()) {
            return (cb.top() + cs.top()) / 2.0;
        }
        else if (cb.size() > cs.size()) {
            return cb.top();
        }
        else {
            return cs.top();
        }
    }
};

int main() {
    Offer41();
    return 0;
}