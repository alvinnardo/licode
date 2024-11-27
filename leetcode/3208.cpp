#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfAlternatingGroups(vector<int> colors, int k) {
    // 思路：双指针
    // 从后往前保持最长的连续交替长度
    // 时间 O(n)，空间 O(1)
    int sz = colors.size();
    int len = 0;
    int last = -1;
    // 先获取前 k 个连续的长度
    for (int i = k - 1; i >= 0; i--) {
        if (colors[i] == last) {
            break;
        } else { // i == k + 1 || colors[i] != last
            len++;
            last = colors[i];
        }
    }

    int res = len >= k;
    int j = k % sz;
    while (j != k - 1) {
        if (colors[j] != colors[(sz + j - 1) % sz]) {
            len++;
        } else {
            len = 1;
        }

        res += len >= k;
        j = (j + 1) % sz;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << numberOfAlternatingGroups({0, 1, 0, 1, 0}, 3) << endl;
    // 2
    cout << numberOfAlternatingGroups({0, 1, 0, 0, 1, 0, 1}, 6) << endl;
    // 0
    cout << numberOfAlternatingGroups({1, 1, 0, 1}, 4) << endl;

    return 0;
}
