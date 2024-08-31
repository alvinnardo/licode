#include "../template/head.h"
#include <bits/stdc++.h>

bool canMakeSquare(vector<vector<char>> grid) {
    // 思路：统计
    // 时间 O(1)，空间 O(1)

    auto test = [&](int a, int b) -> bool {
        unordered_map<char, int> umap;
        umap[grid[a][b]]++;
        umap[grid[a + 1][b]]++;
        umap[grid[a][b + 1]]++;
        umap[grid[a + 1][b + 1]]++;
        // 4 0; 3 1; 2 2; 1 3; 0 4
        return umap['B'] != 2;
    };

    return test(0, 0) || test(0, 1) || test(1, 0) || test(1, 1);
}

bool canMakeSquare1(vector<vector<char>> grid) {
    // 思路：模拟
    // 注意审题：题目说可以三个以上黑的或三个以上白的
    // 时间 O(1)，空间 O(1)

    auto test = [&](int a, int b) -> bool {
        int wh = 0, bl = 0;
        wh += (grid[a][b] == 'W') + (grid[a][b + 1] == 'W') +
              (grid[a + 1][b] == 'W') + (grid[a + 1][b + 1] == 'W');
        bl += (grid[a][b] == 'B') + (grid[a][b + 1] == 'B') +
              (grid[a + 1][b] == 'B') + (grid[a + 1][b + 1] == 'B');
        return wh >= 3 || bl >= 3;
    };

    return test(0, 0) || test(0, 1) || test(1, 0) || test(1, 1);
}

int main(int argc, char *argv[]) {
    // 1
    cout << canMakeSquare({{'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'B'}})
         << endl;
    // 0
    cout << canMakeSquare({{'B', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'B'}})
         << endl;
    // 1
    cout << canMakeSquare({{'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'W'}})
         << endl;

    return 0;
}
