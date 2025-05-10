#include "../template/head.h"
#include <bits/stdc++.h>

bool threeConsecutiveOdds(vector<int> arr) {
    // 思路：模拟
    // 时间 O(n), 空间 O(1)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] & 1) {
            arr[i] = i > 0 ? arr[i - 1] + 1 : 1;

            if (arr[i] == 3) {
                return true;
            }

        } else {
            arr[i] = 0;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    // 0
    cout << threeConsecutiveOdds({2, 6, 4, 1}) << endl;
    // 1
    cout << threeConsecutiveOdds({1, 2, 34, 3, 4, 5, 7, 23, 12}) << endl;

    return 0;
}
