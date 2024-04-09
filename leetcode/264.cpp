#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// dp
int nthUglyNumber(int n) {
    // 三个指针
    vector<int> res;
    res.push_back(1);

    // 每个数组中的数都能和这三个指针相乘
    // 但是和某个指针乘完之后不能再和其相乘
    // 如果有两个相等，那么取位置小的数
    // {位置，值，权值}
    vector<vector<int>> p{{0, 2, 2}, {0, 3, 3}, {0, 5, 5}};
    while (res.size() < n) {
        for (auto &t : p) {
            if (t[1] <= res.back()) {
                t[0]++;
                t[1] = res[t[0]] * t[2];
            }
        }

        sort(p.begin(), p.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
             });

        auto &head = p[0];
        res.push_back(head[1]);
        head[0]++;
        head[1] = res[head[0]] * head[2];
    }

    return res.back();
}

// 最小堆
int nthUglyNumber_minHeap(int n) {
    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
    pq.push(1);
    unordered_set<int64_t> uset;

    int64_t res = 0;
    while (!pq.empty()) {
        auto t = pq.top();
        --n;
        if (n == 0) { // 第 n 次弹出的就是结果
            res = t;
            break;
        }

        pq.pop();
        for (auto i : {t * 2, t * 3, t * 5}) {
            // cout << i << endl;
            if (uset.find(i) == uset.end()) {
                uset.insert(i);
                pq.push(i);
            }
        }
    }

    return res;
}

// 枚举法
void createUglyNumber(int n) {

    vector<int> res;
    auto isUgly = [&](int num) {
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                return false;
            }
        }
        return true;
    };
    for (int i = 1; i < INT_MAX; i++) {
        if (isUgly(i)) {
            res.push_back(i);
            cout << res.size() << ": " << i << endl;
        }
        if (res.size() == 1690) {
            break;
        }
    }

    printVector(res);
}

int main(void) {
    // createUglyNumber(1690);
    cout << nthUglyNumber(1) << endl;
    cout << nthUglyNumber(10) << endl;
    cout << nthUglyNumber(1690) << endl;

    return 0;
}
