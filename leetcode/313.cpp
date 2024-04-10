#include "../template/head.h"
#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;

int nthSuperUglyNumber(int n, vector<int> primes) {

    // 题解：时间 O(mn)
    int sz = primes.size();
    vector<int64_t> dp(n + 1);
    vector<int> pointer(sz, 0); // 下标
    vector<int64_t> nums(sz, 1);

    for (int i = 1; i <= n; i++) {
        int64_t minv = INT_MAX;
        for (int j = 0; j < sz; j++) {
            minv = min(minv, nums[j]);
        }

        dp[i] = minv;
        for (int j = 0; j < sz; j++) {
            if (nums[j] <= dp[i]) {
                pointer[j]++;
                nums[j] = dp[pointer[j]] * primes[j];
            }
        }
    }

    return dp[n];
}

struct cmp {
    bool operator()(const vector<int64_t> &a, const vector<int64_t> &b) {
        return a[2] == b[2] ? a[0] > b[0] : a[2] > b[2];
    }
};

int nthSuperUglyNumber_my(int n, vector<int> primes) {

    // 不能使用优先队列，存储的无用值可能会超出范围
    // 直接使用 DP, 每个数都有资格乘 primes 的数，选最小的数，添加到数组中
    // 不能使用优先队列，存储的无用值可能会超出范围
    // 直接使用 DP, 每个数都有资格乘 primes 的数，选最小的数，添加到数组中
    vector<int> res{1};

    // 优先队列的插入是 O(logn) 的, 小根堆
    priority_queue<vector<int64_t>, vector<vector<int64_t>>, cmp> pq;
    for (int prime : primes) {
        pq.push({0, prime, prime});
    }

    // printVector(pq.top());
    while (res.size() < n) {
        auto t = pq.top();
        pq.pop();

        // 没找到
        if (t[2] > res.back()) {
            res.push_back(t[2]);
        }
        while (t[2] <= res.back()) {
            t[0]++;
            t[2] = res[t[0]] * t[1];
        }
        pq.push(t);
    }

    return res.back();
}
int main(void) {
    cout << nthSuperUglyNumber(12, {2, 7, 13, 19}) << endl;
    cout << nthSuperUglyNumber(1, {2, 3, 5}) << endl;
    cout << nthSuperUglyNumber(67, {2, 997}) << endl;
    cout << nthSuperUglyNumber(
                100000, {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,
                         37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,
                         83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137,
                         139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
                         197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                         263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
                         331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389,
                         397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457})
         << endl;

    return 0;
}
