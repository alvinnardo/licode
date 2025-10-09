#include "../template/head.h"
#include <bits/stdc++.h>

long long minTime(vector<int> &&skill, vector<int> &&mana) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(m)

    // 模拟流水线
    // 当前部分运行结束时间为
    // max(上一部分本次结束时间, 当前部分上一次结束时间) + 当前部分本次运行时间
    // 还需要回溯计算每个部分实际运行结束时间
    long long res{};
    int n = skill.size(), m = mana.size();
    // 这里不需要存放所有中间结果，每个部分只和上一个部分有关
    // vector<long long> vec(m);
    long long pre_part{}; // 上一部分的结束时间

    vector<long long> cur(n);    // 存放本次运算乘积的结果
    long long tot{}, last_tot{}; // 存放本次运算乘积结果的总和

    for (int i = 0; i < m; i++) {
        last_tot = tot;
        tot = 0;

        for (int j = 0; j < n; j++) { // 遍历流水线每个部分
            // 先回溯处理上一次的结果
            // 如果是第一个阶段，根据上次结果找到第一阶段结束时间
            // 后面的可以推出来
            if (j == 0) {
                pre_part = res - last_tot + cur[j];
                res = 0; // 后面有一个比较，这里清零后面逻辑不动
            } else {
                pre_part += cur[j];
            }

            // 计算本部分流水线时间
            cur[j] = skill[j] * mana[i];
            tot += cur[j];

            // 上一部分的结束时间 和 当前部分上一次的结束时间的最大值
            // 再加上当前部分本次运行时间
            res = max(res, pre_part) + cur[j];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 110
    cout << minTime({1, 5, 2, 4}, {5, 1, 4, 2}) << endl;
    // 5
    cout << minTime({1, 1, 1}, {1, 1, 1}) << endl;
    // 21
    cout << minTime({1, 2, 3, 4}, {1, 2}) << endl;

    return 0;
}
