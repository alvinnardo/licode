#include "../template/head.h"
#include <bits/stdc++.h>

int numRescueBoats(vector<int> people, int limit) {
    // 思路：排序 + 双指针
    // 时间 O(nlogn)，空间 O(logn)
    sort(people.begin(), people.end());
    int sz = people.size();
    int l = 0, r = sz - 1;
    int cnt = 0;
    while (l <= r) {
        if (l == r || people[l] + people[r] <= limit) {
            cnt++;
            l++;
            r--;
        } else {
            cnt++;
            r--;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 1
    cout << numRescueBoats({1, 2}, 3) << endl;
    // 3
    cout << numRescueBoats({3, 2, 2, 1}, 3) << endl;
    // 4
    cout << numRescueBoats({3, 5, 3, 4}, 5) << endl;
    // 3
    cout << numRescueBoats({1, 5, 3, 5}, 7) << endl;
    // 3
    cout << numRescueBoats({3, 8, 7, 1, 4}, 9) << endl;

    return 0;
}
