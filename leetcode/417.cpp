#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> pacificAtlantic(vector<vector<int>> heights) {

    // 错误思路1：遍历，存放上下左右的最大值
    // 正确思路2：上面的思路有问题，这道题模拟水流流动，沿梯度小的位置流走
    // 两次 DFS，一次从左上的点 DFS，一次从右下的点 DFS

    int m = heights.size(), n = heights[0].size();

    vector<vector<int>> vec(m, vector<int>(n)), ans;

    int common = 3;
    function<void(int, int, int, int)> dfs = [&](int i, int j, int mflag,
                                                 int oflag) {
        if (vec[i][j] == mflag || vec[i][j] == common) {
            return;
        }

        if (vec[i][j] == oflag) {
            vec[i][j] = common;
            ans.push_back({i, j});
        } else {
            vec[i][j] = mflag;
        }

        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j]) {
            dfs(i - 1, j, mflag, oflag);
        }
        if (i + 1 < m && heights[i + 1][j] >= heights[i][j]) {
            dfs(i + 1, j, mflag, oflag);
        }
        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) {
            dfs(i, j - 1, mflag, oflag);
        }
        if (j + 1 < n && heights[i][j + 1] >= heights[i][j]) {
            dfs(i, j + 1, mflag, oflag);
        }
    };

    for (int i = 0; i < n; i++) {
        dfs(0, i, 1, 2);     // 第一行
        dfs(m - 1, i, 2, 1); // 最后一行
    }
    for (int i = 0; i < m; i++) {
        dfs(i, 0, 1, 2);     // 第一列
        dfs(i, n - 1, 2, 1); // 最后一列
    }

    return ans;
}

int main(int argc, char *argv[]) {
    // {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}}
    printVectorVector(pacificAtlantic({{1, 2, 2, 3, 5},
                                       {3, 2, 3, 4, 4},
                                       {2, 4, 5, 3, 1},
                                       {6, 7, 1, 4, 5},
                                       {5, 1, 1, 2, 4}}));
    // {{0,0},{0,1},{1,0},{1,1}}
    printVectorVector(pacificAtlantic({{2, 1}, {1, 2}}));

    return 0;
}
