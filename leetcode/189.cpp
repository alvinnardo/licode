#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> nums, int k) {
    int sz = nums.size();
    k %= sz;

    if (k == 0) {
        return;
    }

    // 题解法3: 先全翻转，然后再对两部分分别翻转
    // 太 6 了
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    printVector(nums);
}

void rotate_my(vector<int> nums, int k) {
    int sz = nums.size();
    k %= sz;

    if (k == 0) {
        return;
    }

    auto move = [&](int t) {
        int f = nums[0];
        int pos = -1;
        while (pos != 0) {
            if (pos == -1) {
                pos = 0;
            }

            int pre = (pos + sz - t) % sz;
            nums[pos] = nums[pre];
            pos = pre;
        }

        nums[(sz + t) % sz] = f;
    };

    // 必须 sz 和 k 的最大公约数是 1 才行
    while (__gcd(k, sz) != 1) {
        move(1);
        --k;
    }
    move(k);

    printVector(nums);
}

int main(void) {
    rotate({1, 2, 3, 4, 5, 6, 7}, 1);
    rotate({1, 2, 3, 4, 5, 6, 7}, 2);
    rotate({1, 2, 3, 4, 5, 6, 7}, 3);
    rotate({1, 2, 3, 4, 5, 6, 7}, 4);
    rotate({1, 2, 3, 4, 5, 6, 7}, 5);
    rotate({1, 2, 3, 4, 5, 6, 7}, 6);
    rotate({1, 2, 3, 4, 5, 6, 7}, 7);
    rotate({1, 2, 3, 4, 5, 6, 7}, 8);
    rotate({1, 2, 3, 4, 5, 6, 7}, 11);
    rotate({1, 2, 3, 4, 5, 6, 7}, 14);
    rotate({1, 2, 3, 4, 5, 6, 7}, 17);
    rotate({1, 2, 3, 4, 5, 6}, 1);
    rotate({1, 2, 3, 4, 5, 6}, 2);
    rotate({1, 2, 3, 4, 5, 6}, 3);
    rotate({1, 2, 3, 4, 5, 6}, 4);
    rotate({1, 2, 3, 4, 5, 6}, 5);
    rotate({1, 2, 3, 4, 5, 6}, 6);
    rotate({1, 2, 3, 4, 5, 6}, 7);
    rotate({1, 2, 3, 4, 5, 6}, 8);
    rotate({1, 2, 3, 4, 5, 6}, 11);
    rotate({1, 2, 3, 4, 5, 6}, 14);
    rotate({1, 2, 3, 4, 5, 6}, 17);
    rotate({-1, -100, 3, 99}, 2);
    rotate({-1, -100, 3, 99}, 0);

    return 0;
}
