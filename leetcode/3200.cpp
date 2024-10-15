#include "../template/head.h"
#include <bits/stdc++.h>

int maxHeightOfTriangle(int red, int blue) {
    // 思路：模拟
    // 时间 O(logn)，空间 O(1)
    auto getLevel = [](int l, int r) {
        int cnt = 1;
        while (1) {
            if (l < cnt) {
                break;
            }
            l -= cnt++;

            if (r < cnt) {
                break;
            }
            r -= cnt++;
        }

        return cnt - 1;
    };

    return max(getLevel(red, blue), getLevel(blue, red));
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxHeightOfTriangle(2, 4) << endl;
    // 2
    cout << maxHeightOfTriangle(2, 1) << endl;
    // 1
    cout << maxHeightOfTriangle(1, 1) << endl;
    // 2
    cout << maxHeightOfTriangle(10, 1) << endl;

    return 0;
}
