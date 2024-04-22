#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

int combinationSum4(vector<int> nums, int target) {

    // 时间: O(mn) + O(nlogn)
    // 防止中间溢出
    vector<int64_t> dp(target + 1);
    dp[0] = 1; // 从 0 转过来算一次

    // 递增，后面遇到负值就停止
    sort(nums.begin(), nums.end());

    for (int i = 1; i <= target; i++) {
        for (auto &n : nums) {
            int t = i - n;
            if (t >= 0) {
                if (dp[t] < INT_MAX) { // 防止溢出
                    dp[i] += dp[t];
                }
            } else {
                break;
            }
        }
    }

    return dp[target];
}

int main(void) {
    // 7
    cout << combinationSum4({1, 2, 3}, 4) << endl;
    // 0
    cout << combinationSum4({9}, 3) << endl;
    // 1
    cout << combinationSum4(
                {{10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120,
                  130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240,
                  250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360,
                  370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480,
                  490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600,
                  610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720,
                  730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840,
                  850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960,
                  970, 980, 990, 111}},
                999)
         << endl;
    return 0;
}
