#include "../template/head.h"
#include <bits/stdc++.h>

int finalValueAfterOperations(vector<string> &&operations) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int res{}, sz = operations.size();
    for (auto &it : operations) {
        if (it[0] == 'X') {
            if (it[1] == '+') {
                res++;
            } else {
                res--;
            }
        } else {
            if (it[0] == '+') {
                res++;
            } else {
                res--;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << finalValueAfterOperations({"--X", "X++", "X++"}) << endl;
    // 3
    cout << finalValueAfterOperations({"++X", "++X", "X++"}) << endl;
    // 0
    cout << finalValueAfterOperations({"X++", "++X", "--X", "X--"}) << endl;

    return 0;
}
