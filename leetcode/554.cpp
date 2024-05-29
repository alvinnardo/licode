#include "../template/head.h"
#include <bits/stdc++.h>

int leastBricks(vector<vector<int>> wall) {
    // 思路：前缀和 + 哈希表
    // 每一行求前缀和，可以表示哪个位置有空隙
    // 求空隙最多的地方，就是穿墙最少的，注意最后一个位置不能算
    // 如果哈希表最后为空，表示没有空隙，返回层数
    // 时间：O(nm)，空间：O(nm)，n 是行数，m 是每行中砖的平均数

    int maxv = 0;
    unordered_map<int, int> umap;
    for (auto &row : wall) {
        int sum = 0; // 每一层求前缀和
        for (int i = 0; i < row.size() - 1; i++) {
            sum += row[i];
            maxv = max(maxv, ++umap[sum]);
        }
    }

    return wall.size() - maxv;
}

int main(int argc, char *argv[]) {
    // 2
    cout << leastBricks({{1, 2, 2, 1},
                         {3, 1, 2},
                         {1, 3, 2},
                         {2, 4},
                         {3, 1, 2},
                         {1, 3, 1, 1}})
         << endl;
    // 3
    cout << leastBricks({{3}, {3}, {3}}) << endl;
    // 1
    cout << leastBricks({{1}}) << endl;

    return 0;
}
