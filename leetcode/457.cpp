#include "../template/head.h"
#include <bits/stdc++.h>

bool circularArrayLoop(vector<int> nums) {

    // 思路：单指针移动，第一遍要保证全真或全负，如果又遇到表示有环
    // 每个元素要有一个标志位，再次遇到该标志位表示有环
    // 时间 O(n)，空间 O(1)

    int sz = nums.size();
    // 转移下标
    auto getNum = [&](int pos) {
        if (nums[pos] > 0) {
            return (pos + nums[pos]) % sz;
        }

        // 如 size = 3, nums[pos] = -1000
        return (pos + sz + nums[pos] % sz) % sz;
    };

    int step = 10000; // 标志位
    for (int i = 0; i < sz; i++) {
        if (nums[i] / 10000 > 0) {
            continue;
        }

        // 对每个元素探测是否有环
        int t = i;
        int begin = 0;

        while (nums[t] / 10000 == 0) {
            if (begin == 0) {
                begin = nums[i] > 0 ? 1 : -1;
            } else if (begin > 0 && nums[t] < 0 || begin < 0 && nums[t] > 0) {
                break;
            }

            int p = t, tt = getNum(t); // 转移下标
            if (t == tt) { // 长度为 1
                break;
            } else {
                t = tt;
            }
            nums[p] = step; // 置标志位
        }

        if (nums[t] == step) {
            return true;
        }

        step += 10000;
    }

    return false;
}

int main(int argc, char *argv[]) {
    // 1
    cout << circularArrayLoop({2, -1, 1, 2, 2}) << endl;
    // 0
    cout << circularArrayLoop({-1, 2}) << endl;
    // 0
    cout << circularArrayLoop({-2, 1, -1, -2, -2}) << endl;

    return 0;
}
