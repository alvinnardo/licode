#include "../template/head.h"
#include <bits/stdc++.h>

int getWinner(vector<int> arr, int k) {
    // 思路：保留最大值
    // 时间 O(n)，空间 O(1)
    pair<int, int> cur{arr[0], 0};
    for (int i = 1; i < arr.size(); i++) {
        if (cur.first > arr[i]) {
            cur.second++;
        } else {
            cur.first = arr[i];
            cur.second = 1;
        }

        if (cur.second >= k) {
            break;
        }
    }

    return cur.first;
}

int main(int argc, char *argv[]) {
    // 2
    cout << getWinner({1, 2}, 2) << endl;
    // 5
    cout << getWinner({2, 1, 3, 5, 4, 6, 7}, 2) << endl;
    // 3
    cout << getWinner({3, 2, 1}, 10) << endl;
    // 9
    cout << getWinner({1, 9, 8, 2, 3, 7, 6, 4, 5}, 7) << endl;
    // 99
    cout << getWinner({1, 11, 22, 33, 44, 55, 66, 77, 88, 99}, 1000000000)
         << endl;
    // 25
    cout << getWinner({1, 25, 35, 42, 68, 70}, 1) << endl;

    return 0;
}
