#include "../template/head.h"
#include <bits/stdc++.h>
int minDays(int n) {
    // 可以用记忆化搜索
    // 将吃 1 个橘子的操作转化为吃 2 个或 吃 3 个的操作
    // 吃 1次 1 个橘子之后可以全部转化为吃 2 个橘子
    // 最多吃 2 次 1 个橘子之后可以全部转化为 吃 3 个橘子
    // 时间 O(logn * logn)，空间 O(logn * logn)

    unordered_map<int, int> umap;

    function<int(int)> dfs = [&](int val) {
        if (val <= 1) {
            return val;
        }

        if (umap.count(val)) {
            return umap[val];
        }

        return umap[val] =
                   min(val % 2 + 1 + dfs(val / 2), val % 3 + 1 + dfs(val / 3));
    };

    return dfs(n);
}

int minDays_my(int n) {
    // 思路：不能是 O(n) 的 DP，因为 n 最大 为 2*10^9
    // 所以要找到 O(logn) 的算法
    // 用层次遍历, 如果之前遇到过，就不处理该值
    // 时间 O(logn * logn), 空间 (logn * logn)
    if (n == 1) {
        return 1;
    }

    unordered_set<int> uset;
    queue<int> qu;
    qu.push(n);

    int level = 1;
    while (!qu.empty()) {
        int cnt = qu.size();
        level++;
        while (cnt--) {
            auto t = qu.front();
            qu.pop();
            if (t == 2) {
                return level;
            }
            int val = t - 1;
            if (uset.find(val) == uset.end()) {
                qu.push(val);
                uset.insert(val);
            }
            if (t % 2 == 0) {
                int val = t >> 1;
                if (val == 1) {
                    return level;
                }
                if (uset.find(val) == uset.end()) {
                    qu.push(val);
                    uset.insert(val);
                }
            }
            if (t % 3 == 0) {
                int val = t / 3;
                if (val == 1) {
                    return level;
                }
                if (uset.find(val) == uset.end()) {
                    qu.push(val);
                    uset.insert(val);
                }
            }
        }
    }

    return level;
}

int main(int argc, char *argv[]) {
    // 4
    cout << minDays(10) << endl;
    // 3
    cout << minDays(6) << endl;
    // 1
    cout << minDays(1) << endl;
    // 6
    cout << minDays(56) << endl;
    // 33
    cout << minDays(236287367) << endl;
    // 31
    cout << minDays(1000000000) << endl;
    // 32
    cout << minDays(2000000000) << endl;

    return 0;
}
