#include "../template/head.h"
#include <bits/stdc++.h>

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // 题解：动态规划，就是将我的思路转一下
    int mod = 1e9 + 7, cnt = 0;
    // 第一个维度是步数，每走一步又一个矩阵的状态
    vector<vector<vector<int>>> dp(maxMove + 1,
                                   vector<vector<int>>(m, vector<int>(n)));
    // 0 步的时候每个位置的可能数
    dp[0][startRow][startColumn] = 1;

    int row[] = {1, -1, 0, 0};
    int col[] = {0, 0, 1, -1};

    for (int i = 0; i < maxMove; i++) {
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                int t = dp[i][a][b];
                if (t == 0) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {
                    // 出界
                    int newa = a + row[d], newb = b + col[d];
                    if (newa < 0 || newa >= m || newb < 0 || newb >= n) {
                        cnt = ((long long)cnt + t) % mod;
                    } else {
                        // 这里可以取余，因为所有加数都可以取余再相加
                        dp[i + 1][newa][newb] =
                            ((long long)dp[i + 1][newa][newb] + t) % mod;
                    }
                }
            }
        }
    }

    return cnt;
}

int findPaths_my(int m, int n, int maxMove, int startRow, int startColumn) {
    // 思路：层序遍历 + 哈希表
    // 层序遍历模拟每次走一步，哈希表保存当前能走到的位置
    // 时间 O(maxMove * m * n)，空间 O(m * n)

    int cnt = 0;
    int mod = 1e9 + 7;
    vector<vector<int>> vec(m, vector<int>(n));
    unordered_map<int, int> umap;

    umap[startRow * 100 + startColumn]++;

    int row[] = {1, -1, 0, 0};
    int col[] = {0, 0, 1, -1};

    // 统计每一步
    for (int i = 0; i < maxMove; i++) {
        unordered_map<int, int> tmap;
        int a, b, t;
        for (auto &it : umap) {
            // 四个方向进行统计
            a = it.first / 100;
            b = it.first % 100, t = it.second;
            for (int d = 0; d < 4; d++) {
                // 出界
                if (a + row[d] < 0 || a + row[d] >= m || b + col[d] < 0 ||
                    b + col[d] >= n) {
                    cnt = ((long long)cnt + t) % mod;
                } else {
                    // 这里可以取余，因为所有加数都可以取余再相加
                    int p = (a + row[d]) * 100 + (b + col[d]);
                    tmap[p] = ((long long)tmap[p] + t) % mod;
                }
            }
        }

        umap = tmap;
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 6
    cout << findPaths(2, 2, 2, 0, 0) << endl;
    // 12
    cout << findPaths(1, 3, 3, 0, 1) << endl;
    // 678188903
    cout << findPaths(50, 50, 50, 0, 0) << endl;

    return 0;
}
