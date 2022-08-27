#include "../helper.h"

vector<int> topKFrequent(vector<int>&& nums, int k) {
    // 1. calculate nums' frequencies
    unordered_map<int, int> numToCount;
    for (auto x : nums) {
        numToCount[x] += 1;
    }
    // 2. prepare the min heap
    using NumCountPair = pair<int, int>; // <num, count>
    auto cmp = [](const NumCountPair& lhs, const NumCountPair rhs) {
        return lhs.second > rhs.second; // compare by num's frequency
    };
    priority_queue<NumCountPair, vector<NumCountPair>, decltype(cmp)> minHeap{ cmp };

    // 3. add item of hashmap to the minheap of K size 
    for (const auto& [value, count] : numToCount) {
        if (minHeap.size() < k) {
            minHeap.emplace(value, count);
        }
        else if (count > minHeap.top().second) {
            // add only if new num's count is larger than the top of the minheap.
            minHeap.pop();
            minHeap.emplace(value, count);
        }
    }
    // 4. print the minheap.
    vector<int> res;
    for (; not minHeap.empty(); minHeap.pop()) {
        res.emplace_back(minHeap.top().first);
    }
    return res;
}

void demo1() {
    auto cmp = [](const pair<double, int>& p1, const pair<double, int>& p2) {
        return p1.second > p2.second;
    };

    priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(cmp)> heap{ cmp };

    heap.emplace(1.0, 2);
    heap.emplace(19.0, 5);
    heap.emplace(11.0, 3);
    heap.emplace(5.0, 1);

    for (; not heap.empty(); heap.pop()) {
        cout << heap.top().first;
    }
}

class Solution061 { // 061. 和最小的 k 个数对
public:
    vector<vector<int>> kSmallestPairs_bad(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int M = nums1.size(), N = nums2.size();
        if (M * N <= k) {
            for (auto n1 : nums1) {
                for (auto n2 : nums2) {
                    res.push_back({ n1, n2 });
                }
            }
            return res;
        }

        using UV = pair<int, int>;
        auto cmp = [&](const UV& uv1, const UV& uv2) {
            return (nums1[uv1.first] + nums2[uv1.second]) > (nums1[uv2.first] + nums2[uv2.second]);
        };
        priority_queue<UV, vector<UV>, decltype(cmp)> minHeap{ cmp };

        int lastp1 = 0, lastp2 = 0;
        for (int i = 0; i < k; i++) {
            for (int p2 = 0; p2 < nums2.size() && p2 < k; p2++) {
                for (int p1 = 0; p1 < nums1.size() && p1 < k; p1++) {
                    if (minHeap.size() < k) {
                        //cout << nums1[p1] << "," << nums2[p2] << ";\n";
                        minHeap.emplace(p1, p2);
                        lastp1 = p1;
                        lastp2 = p2;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        //cout << "p1=" << lastp1 << ", p2=" << lastp2 << endl;

        for (int i = 0; i < k; i++) {
            auto minPair = minHeap.top();
            res.emplace_back(vector{ nums1[minPair.first], nums2[minPair.second] });
            minHeap.pop();
            int next_p2 = minPair.second + 1;
            if (next_p2 < nums2.size()) {
                if (next_p2 > lastp2 or (next_p2 == lastp2 && minPair.first > lastp1)) {
                    //cout << "lp2=" << lastp2 << ", np2=" << next_p2 << "\n";
                    minHeap.emplace(minPair.first, minPair.second + 1);
                }
            }
        }
        return res;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // 1. prepare min heap, whose top is the smallest sum of pairs
        using Ids = pair<int, int>; // indice of nums1 and nums2.
        auto cmp = [&](const Ids& lhs, const Ids& rhs) {
            auto sum = [&](const Ids& ids) {
                return nums1[ids.first] + nums2[ids.second];
            };
            return sum(lhs) > sum(rhs);
        };
        priority_queue<Ids, vector<Ids>, decltype(cmp)> pq{ cmp };

        // 2. add k items of the nums, pairing with nums2[0]
        for (int i = 0; i < k && i < nums1.size(); i++) {
            pq.emplace(i, 0);
        }

        vector<vector<int>> res;
        // 3. add ! pq.empty can adapt to m*n < k. if m*n < k, then pop all the heap
        for (int i = 0; i < k && !pq.empty(); i++) {
            auto ids = pq.top(); pq.pop();
            res.push_back({ nums1[ids.first], nums2[ids.second] });
            // 3.1 add one more pair to minheap.
            if (ids.second + 1 < nums2.size()) { // key step, add next id of nums2.
                pq.emplace(ids.first, ids.second + 1);
            }
        }
        return res;
    }

    void test1() {
        vector<int> v1 = { 1,2,3,9,10 };
        vector<int> v2 = { 4,5,6,8 };
        int k = 13;
        for (auto v : kSmallestPairs(v1, v2, k)) {
            print(v);
        }
    }
};

int main()
{
    // topKFrequent({33,33, 22, 11,11,11,44,44}, 2);
    Solution061().test1();
    return 0;
}
