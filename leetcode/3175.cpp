#include "../template/head.h"
#include <bits/stdc++.h>

// 做了 30 分钟
int findWinningPlayer(vector<int> skills, int k) {
    // 思路: 模拟 + 双指针
    // 一轮遍历之后留下的是最大的，它跟剩下的比，最后连胜的就是它
    // 时间 O(n)，空间 O(1)
    int winer = 0, win_times = 0, sz = skills.size();
    for (int j = 1; j < sz; j++) {
        if (skills[winer] > skills[j]) {
            win_times++;
        } else {
            winer = j;
            win_times = 1;
        }

        if (win_times == k) {
            break;
        }
    }

    return winer;
}

int main(int argc, char *argv[]) {
    // 2
    cout << findWinningPlayer({4, 2, 6, 3, 9}, 2) << endl;
    // 1
    cout << findWinningPlayer({2, 5, 4}, 3) << endl;

    return 0;
}
