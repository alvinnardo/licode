#include "../template/head.h"
#include <bits/stdc++.h>

int jump(vector<int> nums) {
    // 题解：贪心
    // 时间 O(n)，空间 O(1)

    // 记录能到达的最大位置，每次本次最大位置时步数 + 1
    // max_pos 是活跃的，记录下一次能够到达的最大位置
    int sz = nums.size();
    int max_pos{}, end{}, step{};
    for (int i = 0; i < sz - 1; ++i) {
        // 不需要判断
        // if (i <= max_pos) { // 能够到达 i，则更新下一次的最大位置
        // 类似层次遍历流程，处理下一层能达到最远位置
        // 如果到达本层的最远位置，则层数 +1
        max_pos = max(max_pos, i + nums[i]);
        if (i == end) {
            end = max_pos;
            ++step;
        }
        // }
    }

    return step;
}

int jump1(vector<int> nums) {
    // 思路：贪心 + DP
    // 时间 O(n)，空间 O(n)

    int sz = nums.size();
    int res{}, pos{};
    vector<pair<int, int>> step_vec{{0, 0}};
    for (int i = 0; i < sz; ++i) {
        if (step_vec.back().first >= sz - 1) {
            break;
        }

        // 肯定能到达
        while (step_vec[pos].first < i) {
            ++pos;
        }

        // 到达该位置最小步数
        int step = step_vec[pos].second;
        if (nums[i] + i > step_vec.back().first) {
            step_vec.emplace_back(nums[i] + i, step + 1);
        }
    }

    return step_vec.back().second;
}

int main(int argc, char *argv[]) {
    // 2
    cout << jump({2, 3, 1, 1, 4}) << endl;
    // 2
    cout << jump({2, 3, 0, 1, 4}) << endl;
    // 3
    cout << jump({7,  13, 13, 15, 14, 17, 1,  2,  19, 0,  0,  8, 15, 5, 11,
                  10, 13, 12, 14, 15, 11, 13, 17, 13, 20, 10, 7, 8,  8, 3})
         << endl;
    // 0
    cout << jump({0}) << endl;

    return 0;
}
