#include "../template/head.h"
#include <bits/stdc++.h>

int carFleet(int target, vector<int> position, vector<int> speed) {
    // 思路：模拟 + 排序
    // 时间 O(nlogn)，空间 O(n)

    // 题目给出每个 position 位置不同
    // 有相同的也可以，取速度最小的就行

    // 先按位置排序一下，然后依次遍历，如果后面一个时间更长，那么就能合成一个车队
    // 我离终点远，到终点时间比下一个更短，那么久会遇上

    int sz = position.size();
    vector<int> pos_vec(sz);
    iota(pos_vec.begin(), pos_vec.end(), 0);

    sort(pos_vec.begin(), pos_vec.end(),
         [&](int a, int b) { return position[a] < position[b]; });

    double time = -1;
    int res = 0;
    for (int i = sz - 1; i >= 0; i--) {
        int pos = position[pos_vec[i]], sp = speed[pos_vec[i]];
        double it_time = (target - pos) * 1.0 / sp;

        // 把距离远的，时间也长的，即赶不上的，新建立一个车队
        if (i == sz - 1 || it_time > time) {
            time = it_time;
            res++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << carFleet(12, {10, 8, 0, 5, 3}, {2, 4, 1, 1, 3}) << endl;
    // 1
    cout << carFleet(10, {3}, {3}) << endl;
    // 1
    cout << carFleet(100, {0, 2, 4}, {4, 2, 1}) << endl;

    return 0;
}
