#include "../template/head.h"
#include <bits/stdc++.h>

int maxFrequencyElements(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(k)
    std::array<int, 101> arr{};
    int maxv = INT_MIN;
    int maxsum = 0;
    for (int num : nums) {
        ++arr[num];
        if (arr[num] > maxv) {
            maxv = arr[num];
            maxsum = maxv;
        } else if (arr[num] == maxv) {
            maxsum += arr[num];
        }
    }

    return maxsum;
}

int main(int argc, char *argv[]) {
    // 4
    cout << maxFrequencyElements({1, 2, 2, 3, 1, 4}) << endl;
    // 5
    cout << maxFrequencyElements({1, 2, 3, 4, 5}) << endl;

    return 0;
}
