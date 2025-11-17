#include <bits/stdc++.h>
using namespace std;

bool kLengthApart(vector<int> &&nums, int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int pre = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (pre == -1) {
                pre = i;
            } else {
                if (i - pre - 1 < k) {
                    return false;
                }

                pre = i;
            }
        }
    }

    return true;
}

int main(void) {
    // true
    cout << kLengthApart({1, 0, 0, 0, 1, 0, 0, 1}, 2) << endl;
    // false
    cout << kLengthApart({1, 0, 0, 1, 0, 1}, 2) << endl;

    return 0;
}
