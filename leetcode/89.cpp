#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n) {
    // 找规律，下一轮的结果 等于上一轮的结果反向，并把最高位置 1
    vector<int> res{0};
    int t = 1;
    for (int i = 0; i < n; i++) {
        int sz = res.size();
        for (int j = sz - 1; j >= 0; j--) { // 将上次的结果从后往前遍历
            res.push_back(res[j] | t);
        }
        t <<= 1;
    }
    return res;
}

int main(void) {
    for (int i = 1; i <= 8; i++) {
        printVector(grayCode(i));
    }

    return 0;
}
