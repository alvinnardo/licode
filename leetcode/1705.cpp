#include "../template/head.h"
#include <bits/stdc++.h>

struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    }
};

int eatenApples(vector<int> apples, vector<int> days) {
    // 思路：优先队列 + 贪心
    // 时间 O(nlogn)，空间 O(n)
    // 之前的差分数据和区间合并思路都不对
    // 用贪心来模拟，先吃快过期的苹果
    int n = apples.size();

    int res = 0, day = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    while (true) {
        if (day < n) {
            if (apples[day] != 0) {
                pq.emplace(day + days[day] - 1, apples[day]);
            }
        }
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if (t.first < day) {
                continue;
            }

            t.second--;
            res++;
            if (t.second) {
                pq.emplace(t.first, t.second);
            }
            break;
        }

        day++;
        if (pq.empty() && day > n) {
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 7
    cout << eatenApples({1, 2, 3, 5, 2}, {3, 2, 1, 4, 2}) << endl;
    // 5
    cout << eatenApples({3, 0, 0, 0, 0, 2}, {3, 0, 0, 0, 0, 2}) << endl;
    // 10004
    cout << eatenApples({3, 0, 0, 0, 100, 10000}, {3, 0, 0, 0, 1000, 10000})
         << endl;
    // 3
    cout << eatenApples({2, 1}, {5, 100}) << endl;
    // 7
    cout << eatenApples({3, 4}, {5, 7}) << endl;
    // 10
    cout << eatenApples({0, 10, 29, 5, 3, 2, 1, 20000},
                        {0, 1, 2, 3, 4, 5, 100, 2})
         << endl;
    // 4
    cout << eatenApples({2, 1, 10}, {2, 10, 1}) << endl;

    return 0;
}
