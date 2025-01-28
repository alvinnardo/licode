#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> getRow(int rowIndex) {
    // 思路：模拟
    // 时间 O(rowIndex^2)，空间 O(rowIndex)
    // 0: 1
    // 1: 1 1
    // 2: 1 2 1
    // 3: 1 3 3  1
    // 4: 1 4 6  4  1
    // 5: 1 5 10 10 5  1
    // 6: 1 6 15 20 15 6  1
    // 7: 1 7 21 35 35 21 7 1
    // 8: 1 8 28 56 70 56 28 8 1
    if (rowIndex == 0) {
        return {1};
    } else if (rowIndex == 1) {
        return {1, 1};
    }

    vector<int> res{1, 1}, tmp;
    for (int i = 1; i < rowIndex; i++) {
        tmp.push_back(1);
        for (int j = 1; j < res.size(); j++) {
            tmp.push_back(res[j] + res[j - 1]);
        }
        tmp.push_back(1);
        res = tmp;
        tmp.clear();
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {1,3,3,1}
    printVector(getRow(3));
    // {1}
    printVector(getRow(0));
    // {1,1}
    printVector(getRow(1));

    return 0;
}
