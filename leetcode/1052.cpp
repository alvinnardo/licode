#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int> customers, vector<int> grumpy, int minutes) {

    // 滑动窗口，时间 O(n)
    int sum = 0, sz = customers.size();
    int j = 0, maxv = INT_MIN;
    // 计算前面的后面的不能落
    // 除了窗口中的值，其余不生气的都应该加到结果中
    for (int i = 0; i < sz; i++) {
        if (grumpy[i] == 0) {
            sum += customers[i];
        }
    }

    for (int i = 0; i < sz; i++) {
        if (grumpy[i] == 1) {
            sum += customers[i];
        }

        if (i - j + 1 > minutes) {
            if (grumpy[j] == 1) {
                sum -= customers[j];
            }
            j++;
        }

        maxv = max(maxv, sum);
    }
    return maxv;
}

int main(void) {
    // 16
    cout << maxSatisfied({1, 0, 1, 2, 1, 1, 7, 5}, {0, 1, 0, 1, 0, 1, 0, 1}, 3)
         << endl;
    // 1
    cout << maxSatisfied({1}, {0}, 1) << endl;
    // 24
    cout << maxSatisfied({4, 10, 10}, {1, 1, 0}, 2) << endl;

    return 0;
}
