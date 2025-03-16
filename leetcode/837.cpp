#include "../template/head.h"
#include <bits/stdc++.h>

double new21Game(int n, int k, int maxPts) {
    // 思路：差分数组 + 模拟
    // 时间 O(kn)，空间 O(n)

    // 这道题想了好几天，总是找不出规律，一直想 DFS 怎么剪枝优化
    // 周六静下心来，想啊想，终于灵光一现，想出了这个方法
    // 调试过程中发现有很多小细节要注意

    if (k == 0) { // k 为 0，不抽取，则肯定不超过 n
        return 1;
    }

    if (maxPts == 1) { // 全是 1，最后等于 k
        return 1;
    }

    double res = 0, factor = 1.0 / maxPts;

    int cnt = min(n, maxPts); // 初始个数
    // long long 在 10000 的时候，不断累加会溢出，用 double 存
    vector<double> up(n + 1, 0), down(n + 1, 0);
    up[0] = 0;
    // 从第 2 层开始，刚开始的 0 不好处理
    // 初始化第 1 层
    int bng = 1, end = k - 1;
    // 直接存放概率就行，之前想的存放频次，maxPts 为 10000 时候，double 都放不下
    for (int i = 1; i <= cnt; i++) {
        up[i] = factor;
        if (i >= k && i <= n) {
            res += factor;
        }
    }

    int level = 0;
    while (cnt && level < 10000) {
        level++;
        cnt = 0;
        // 处理 1 ~ k - 1
        int down_bng = INT_MAX, down_end = INT_MIN;
        for (int i = bng; i <= end; i++) {
            if (up[i] == 0) {
                continue;
            }

            int left = i + 1, right = i + maxPts + 1;
            if (left < up.size()) {
                down[left] += up[i] * factor;
                down_bng = min(down_bng, left);
            }
            if (right < up.size()) {
                down[right] -= up[i] * factor;
                down_end = max(down_end, right);
            }
        }

        // 1 ~ k - 1 是可以继续的
        // k ~ n 是不继续的
        bool first = true;
        if (down_bng == INT_MAX) {
            down_bng = 1;
        }
        if (down_end == INT_MIN) {
            down_end = down.size() - 1;
        }

        // 要改 down 的值，所以用 pre 存前一个值
        // double pre = down[down_bng - 1];
        double pre = down[down_bng - 1];
        double pre_res = res;
        for (int i = down_bng; i <= down_end; i++) {
            down[i] += pre;
            pre = down[i];
            if (down[i] == 0) {
                up[i] = 0;
                continue;
            }

            if (i >= k && i <= n) { // 不再继续的
                res += down[i];
            } else {         // 小于 k 继续
                if (first) { // 保存下一轮的起点和终点，减少时间
                    bng = i;
                    end = i;
                    first = false;
                } else {
                    end = i;
                }
                cnt++;
            }
            up[i] = down[i];
            down[i] = 0;
        }
    }
    cout << "level: " << level << endl;

    return res;
}

int main(int argc, char *argv[]) {
    // 1.00000
    cout << new21Game(10, 1, 10) << endl;
    // 0.60000
    cout << new21Game(6, 1, 10) << endl;
    // 1
    cout << new21Game(5, 3, 3) << endl;
    cout << new21Game(5, 4, 4) << endl;
    cout << new21Game(5, 3, 10000) << endl;
    // 0.73278
    cout << new21Game(21, 17, 10) << endl;
    // 0.00027
    cout << new21Game(10000, 10000, 10000) << endl;
    cout << new21Game(10000, 10000, 1) << endl;
    // cout << new21Game(10000, 10000, 2) << endl;
    cout << new21Game(10000, 10000, 3) << endl;
    cout << new21Game(10000, 1000, 2) << endl;
    cout << new21Game(10000, 1000, 3) << endl;
    cout << new21Game(10000, 1000, 100) << endl;
    cout << new21Game(10000, 5000, 1) << endl;
    cout << new21Game(10000, 100, 1) << endl;

    return 0;
}
