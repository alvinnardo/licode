#include "../template/head.h"
#include <bits/stdc++.h>

int minCost(string colors, vector<int> &&neededTime) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)
    // 如果相邻的颜色都相同，留下时间最大的
    char pre = ' ';
    int maxv{}, tot{}, res{};
    int len = colors.length();
    for (int i = 0; i <= len; i++) {
        if (i == len) {
            res += tot - maxv;
        } else if (colors[i] != pre) {
            res += tot - maxv;
            pre = colors[i];
            maxv = neededTime[i];
            tot = neededTime[i];
        } else {
            maxv = max(neededTime[i], maxv);
            tot += neededTime[i];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << minCost("abaac", {1, 2, 3, 4, 5}) << endl;
    // 0
    cout << minCost("abc", {1, 2, 3}) << endl;
    // 2
    cout << minCost("aabaa", {1, 2, 3, 4, 1}) << endl;

    return 0;
}
