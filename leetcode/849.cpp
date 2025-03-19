#include "../template/head.h"
#include <bits/stdc++.h>

int maxDistToClosest(vector<int> seats) {
    // 思路：双指针
    // 时间 O(n)，空间 O(1)

    // 直接双指针记录前后位置即可
    int sz = seats.size();
    int maxv = INT_MIN;
    int left = -1, right = -1;
    for (int i = 0; i < sz; i++) { // 先找到第一个右边非空的位置
        if (seats[i]) {
            right = i;
            break;
        }
    }

    for (int i = 0; i < sz; i++) {
        if (seats[i]) {
            while (right < sz) {
                if (++right == sz) {
                    break;
                }
                if (seats[right]) {
                    break;
                }
            }

            while (left < sz) {
                if (seats[++left]) {
                    break;
                }
            }
        } else {
            if (left == -1) {
                maxv = max(maxv, right - i);
            } else if (right == sz) {
                maxv = max(maxv, i - left);
            } else {
                maxv = max(maxv, min(right - i, i - left));
            }
        }
    }

    return maxv;
}

int maxDistToClosest1(vector<int> seats) {
    // 思路：模拟
    // 时间 O(n)，空间 O(m)，m 是非 0 个数

    int sz = seats.size();
    vector<int> vv;
    for (int i = 0; i < sz; i++) { // 保存有人的位置
        if (seats[i]) {
            vv.push_back(i);
        }
    }

    int maxv = INT_MIN;
    int j = 0; // j 保存下一个有人的位置
    for (int i = 0; i < sz; i++) {
        if (seats[i]) {
            j++;
        } else {
            if (j == 0) {
                maxv = max(maxv, vv[j] - i);
            } else if (j == vv.size()) {
                maxv = max(maxv, i - vv[j - 1]);
            } else {
                maxv = max(maxv, min(i - vv[j - 1], vv[j] - i));
            }
        }
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maxDistToClosest({1, 0, 0, 0, 1, 0, 1}) << endl;
    // 3
    cout << maxDistToClosest({1, 0, 0, 0}) << endl;
    // 1
    cout << maxDistToClosest({0, 1}) << endl;

    return 0;
}
