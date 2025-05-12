#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findEvenNumbers(vector<int> digits) {
    // 思路：哈希表
    // 时间 O(n + m)，空间 O(k)，m = 1000，k = 10
    vector<int> vec(10);
    for (int i = 0; i < digits.size(); i++) {
        vec[digits[i]]++;
    }

    vector<int> res;
    // 依次遍历三个数
    for (int i = 1; i < 10; i++) { // 第一个数从 1 开始，不能 0 开头
        if (vec[i] == 0) {
            continue;
        }
        vec[i]--;
        for (int j = 0; j < 10; j++) {
            if (vec[j] == 0) {
                continue;
            }
            vec[j]--;
            for (int k = 0; k < 10; k += 2) {
                if (vec[k] > 0) {
                    res.push_back(i * 100 + j * 10 + k);
                }
            }
            vec[j]++;
        }
        vec[i]++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {102,120,130,132,210,230,302,310,312,320}
    printVector(findEvenNumbers({2, 1, 3, 0}));
    // {222,228,282,288,822,828,882}
    printVector(findEvenNumbers({2, 2, 8, 8, 2}));
    // {}
    printVector(findEvenNumbers({3, 7, 5}));

    return 0;
}
