#include "../template/head.h"
#include <bits/stdc++.h>

int totalFruit(vector<int> &&fruits) {
    // 思路：双指针
    // 时间 O(n)，空间 O(1)
    // 数字代表种类
    int maxv = 0, sz = fruits.size();
    int one = -1, cnt_one = 0, two = -1, cnt_two = 0;
    int j = 0;
    for (int i = 0; i < sz; i++) {
        if (fruits[i] == one) {
            cnt_one++;
        } else if (fruits[i] == two) {
            cnt_two++;
        } else {
            while (cnt_one > 0 && cnt_two > 0) {
                if (fruits[j] == one) {
                    cnt_one--;
                } else if (fruits[j] == two) {
                    cnt_two--;
                }
                j++;
            }

            // 初始逻辑融合在这里
            // 前面先判断种类
            if (cnt_one == 0) {
                cnt_one = 1;
                one = fruits[i];
            } else if (cnt_two == 0) {
                cnt_two = 1;
                two = fruits[i];
            }
        }

        maxv = max(maxv, cnt_one + cnt_two);
    }

    return maxv;
}

int main(int argc, char *argv[]) {
    // 3
    cout << totalFruit({0, 0, 1, 1}) << endl;
    // 3
    cout << totalFruit({1, 2, 1}) << endl;
    // 3
    cout << totalFruit({0, 1, 2, 2}) << endl;
    // 4
    cout << totalFruit({1, 2, 3, 2, 2}) << endl;
    // 5
    cout << totalFruit({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}) << endl;

    return 0;
}
