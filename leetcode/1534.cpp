#include "../template/head.h"
#include <bits/stdc++.h>

int countGoodTriplets(vector<int> arr, int a, int b, int c) {
    // 思路：模拟
    // 时间 O(n3)，空间 O(1)

    int sz = arr.size(), cnt = 0;
    for (int i = 0; i < sz - 2; i++) {
        for (int j = i + 1; j < sz - 1; j++) {
            if (abs(arr[i] - arr[j]) > a) {
                continue;
            }
            for (int k = j + 1; k < sz; k++) {
                if (abs(arr[j] - arr[k]) > b || abs(arr[i] - arr[k]) > c) {
                    continue;
                }
                cnt++;
            }
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 4
    cout << countGoodTriplets({3, 0, 1, 1, 9, 7}, 7, 2, 3) << endl;
    // 0
    cout << countGoodTriplets({1, 1, 2, 2, 3}, 0, 0, 1) << endl;

    return 0;
}
