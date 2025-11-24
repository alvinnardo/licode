#include "../template/head.h"
#include <bits/stdc++.h>

vector<bool> prefixesDivBy5(vector<int> &&nums) {
    // 思路：数学
    // 时间 O(n)，空间 O(1)

    // 取余操作
    // (t * 2 + 1) % 5 = (t % 5) * (2 % 5) + (1 % 5) = (t % 5) * 2 + 1
    // 每一次取 t % 5 的结果
    vector<bool> res;
    int t{}, sz = nums.size();
    for (int i = 0; i < sz; i++) {
        t = ((t % 5) << 1) + nums[i];
        res.push_back((t % 5) == 0 ? 1 : 0);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {true,false,false}
    cout << prefixesDivBy5({0, 1, 1}) << endl;
    // {false,false,false}
    cout << prefixesDivBy5({1, 1, 1}) << endl;

    return 0;
}
