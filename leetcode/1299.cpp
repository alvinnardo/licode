#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> replaceElements(vector<int> arr) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    int pre = -1, sz = arr.size(), t = 0;
    for (int i = sz - 1; i >= 0; i--) {
        t = arr[i];
        arr[i] = pre;
        if (t > pre) {
            pre = t;
        }
    }

    return arr;
}

int main(int argc, char *argv[]) {
    // {18,6,6,6,1,-1}
    printVector(replaceElements({17, 18, 5, 4, 6, 1}));
    // {-1}
    printVector(replaceElements({400}));

    return 0;
}
