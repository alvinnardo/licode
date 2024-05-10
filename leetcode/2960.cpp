#include "../template/head.h"
#include <bits/stdc++.h>

int countTestedDevices(vector<int> batteryPercentages) {
    // 思路：差分思想，因为只对后面的元素有影响，所以可以在遍历时做差分
    // 时间 O(n), 空间 O(1)
    int cnt = 0, sub = 0; // 用来判断当前需要减去的个数
    for (int i : batteryPercentages) {
        if (i - cnt > 0) {
            sub++;
            cnt++;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 3
    cout << countTestedDevices({1, 1, 2, 1, 3}) << endl;
    // 2
    cout << countTestedDevices({0, 1, 2}) << endl;

    return 0;
}
