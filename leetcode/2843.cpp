#include "../template/head.h"
#include <bits/stdc++.h>

int countSymmetricIntegers(int low, int high) {
    // 思路：枚举 + 前缀和
    // 时间 O(n)，空间 O(k)，k 是范围数字的平均位数，这里不超过 4
    // 使用前缀和可以更方便同时求长度和求和

    vector<int> vec;
    auto check = [&](int t) {
        vec.clear();
        while (t) {
            int pre = vec.empty() ? 0 : vec.back();
            vec.push_back(pre + t % 10);
            t /= 10;
        }

        if (vec.size() & 1) {
            return false;
        }

        int mid = (vec.size() - 1) >> 1;
        return vec[mid] == vec.back() - vec[mid];
    };

    int cnt = 0;
    for (int i = low; i <= high; i++) {
        cnt += check(i);
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 9
    cout << countSymmetricIntegers(1, 100) << endl;
    // 4
    cout << countSymmetricIntegers(1200, 1230) << endl;

    return 0;
}
