#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> nums, int k) {
    // 思路：优先队列 + 模拟
    // 时间 O(nlogn)，空间 O(n)

    // 注意数字范围，乘 2 后会超过 INT_MAX
    priority_queue<int, vector<int>, std::greater<int>> pq(nums.begin(),
                                                           nums.end());
    int cnt = 0;
    while (!pq.empty()) {
        // 第一个元素满足
        if (pq.top() >= k) {
            break;
        }

        int t1 = pq.top(); // 第一个数
        pq.pop();

        // 只剩下了一个
        // 题目给出有成立答案，所以不用判断个数
        if (pq.empty()) {
            cnt++;
            break;
        }

        int t2 = pq.top(); // 第二个数
        pq.pop();

        cnt++;

        long long tmp = ((long long)t1 << 1) + t2;
        if (tmp < (long long)k) { // 小于才放
            pq.push(tmp);
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minOperations({2, 11, 10, 1, 3}, 10) << endl;
    // 4
    cout << minOperations({1, 1, 2, 4, 9}, 20) << endl;

    return 0;
}
