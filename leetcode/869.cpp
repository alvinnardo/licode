#include "../template/head.h"
#include <bits/stdc++.h>

bool reorderedPowerOf2(int n) {
    // 思路：模拟 + 哈希表
    // 时间 O(logn)，空间 O(k)，k = 31

    vector<vector<int>> vec{{},
                            {1, 2, 4, 8},
                            {16, 32, 64},
                            {128, 256, 512},
                            {1024, 2048, 4096, 8192},
                            {16384, 32768, 65536},
                            {131072, 262144, 524288},
                            {1048576, 2097152, 4194304, 8388608},
                            {16777216, 33554432, 67108864},
                            {134217728, 268435456, 536870912},
                            {1073741824}};

    vector<int> num(10);
    int cnt = 0;

    while (n) {
        num[n % 10]++;
        n /= 10;
        cnt++;
    }

    auto &v = vec[cnt];
    vector<int> num2;
    for (int t : v) {
        num2.clear();
        num2.assign(10, 0);
        while (t) {
            num2[t % 10]++;
            t /= 10;
        }

        if (num == num2) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    // true
    cout << reorderedPowerOf2(1) << endl;
    // false
    cout << reorderedPowerOf2(10) << endl;

    return 0;
}
