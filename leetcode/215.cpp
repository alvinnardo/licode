#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> nums, int k) {

    // 计数排序
    // -10000 到 10000 共 20001 个数
    vector<int> cnt(20002);

    for (auto &num : nums) {
        ++cnt[num + 10000];
    }

    int idx = 0;
    for (int i = 20001; i >= 0; i--) {
        while (cnt[i]--) {
            ++idx;
            if (idx == k) {
                return i - 10000;
            }
        }
    }
    return -1;
}

int main(void) {
    cout << findKthLargest({3, 2, 1, 5, 6, 4}, 2) << endl;
    cout << findKthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4) << endl;
    return 0;
}
