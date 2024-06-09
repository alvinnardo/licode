#include "../template/head.h"
#include <bits/stdc++.h>

bool isPossible(vector<int> nums) {
    // 思路：计数排序，分解成一个或多个子序列
    // 注意审题，之前的错误都是当做分成两个子序列做的
    // 时间：O(n)，空间 O(k)
    int sz = nums.size();
    int maxv = INT_MIN, minv = INT_MAX;
    for (int i = 0; i < sz; i++) {
        maxv = max(maxv, nums[i]);
        minv = min(minv, nums[i]);
    }

    vector<int> vec(maxv - minv + 1);
    for (int i = 0; i < sz; i++) {
        vec[nums[i] - minv]++;
    }

    int tot = 0;
    while (tot < sz) {
        // 属于同一个序列的频次应该越来越大
        int fre = 0, cnt = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] > fre) {
                fre = vec[i];
            } else if (vec[i] < fre) {
                break;
            }

            if (vec[i] > 0) {
                cnt++;
                vec[i]--;
            }
        }

        tot += cnt;
        if (cnt < 3) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {

    // 1
    cout << isPossible({1, 2, 3, 3, 4, 5}) << endl;
    // 1
    cout << isPossible({1, 2, 3, 3, 4, 4, 5, 5}) << endl;
    // 0
    cout << isPossible({1, 2, 3, 4, 4, 5}) << endl;
    // 1
    cout << isPossible({1, 2, 3, 4, 5, 6}) << endl;
    // 1
    cout << isPossible({1, 1, 1, 2, 2, 2, 3, 3, 3}) << endl;

    return 0;
}
