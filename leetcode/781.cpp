#include "../template/head.h"
#include <bits/stdc++.h>

int numRabbits(vector<int> answers) {
    // 思路：哈希表，{还有几个，说的个数}
    // 如果说的个数 = 还有几个 + 1，处理一下
    // 时间 O(n)，空间 O(k)
    int sum = 0;
    vector<int> vec(1000);
    for (int a : answers) {
        if (++vec[a] == a + 1) {
            sum += vec[a];
            vec[a] = 0;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != 0) {
            sum += i + 1;
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 5
    cout << numRabbits({1, 1, 2}) << endl;
    // 11
    cout << numRabbits({10, 10, 10}) << endl;
    // 1
    cout << numRabbits({0}) << endl;

    return 0;
}
