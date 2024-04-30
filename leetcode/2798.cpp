#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfEmployeesWhoMetTarget(vector<int> hours, int target) {
    int cnt = 0;
    for (auto &hour : hours) {
        if (hour >= target) {
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    // 3
    cout << numberOfEmployeesWhoMetTarget({0, 1, 2, 3, 4}, 2) << endl;
    // 0
    cout << numberOfEmployeesWhoMetTarget({5, 1, 4, 2, 2}, 6) << endl;

    return 0;
}
