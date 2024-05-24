#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> mostCompetitive(vector<int> nums, int k) {
    // 思路：单调栈，要让更小的值留在前面，且要保证后面有充足的数
    // 模式识别：数字更小更有竞争力，所以用单调栈
    // 时间: O(n)，空间 O(n)
    int sz = nums.size();
    int cnt = k;
    if (k == sz) {
        return nums;
    }

    vector<int> res;
    for (int i = 0; i < sz; i++) {
        if (res.empty()) {
            res.push_back(nums[i]);
            cnt--;
            continue;
        }

        // 我数字更小，而且后面的个数也能满足条件
        // 这个地方如果个数不够了，就不判断了，后面会直接添加进去
        while (!res.empty() && nums[i] < res.back() && sz - i - 1 >= cnt) {
            res.pop_back();
            cnt++;
        }

        // 优化 1：如果个数够了，就不放了
        if (res.size() != k) {
            res.push_back(nums[i]);
            cnt--;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {2, 6}
    printVector(mostCompetitive({3, 5, 2, 6}, 2));
    // {2, 3, 3, 4}
    printVector(mostCompetitive({2, 4, 3, 3, 5, 4, 9, 6}, 4));
    // {2, 3, 3, 5, 4, 9, 6}
    printVector(mostCompetitive({2, 4, 3, 3, 5, 4, 9, 6}, 7));
    printVector(mostCompetitive({2, 4, 3, 3, 5, 2, 9, 6}, 5));

    return 0;
}
