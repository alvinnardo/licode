#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：模拟
// 时间 O(n2)，空间 O(n2)
class NeighborSum {
  public:
    vector<pair<int, int>> m_vec;
    const vector<vector<int>> adj_vec{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    const vector<vector<int>> dia_vec{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    NeighborSum(vector<vector<int>> &grid) : m_vec(grid.size() * grid.size()) {
        int n = grid.size();
        auto getVal = [&](const auto &vec, int posi, int posj) -> int {
            int newi = 0, newj = 0, res = 0;
            for (int i = 0; i < vec.size(); i++) {
                newi = posi + vec[i][0];
                newj = posj + vec[i][1];
                if (newi >= 0 && newj >= 0 && newi < n && newj < n) {
                    res += grid[newi][newj];
                }
            }
            return res;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m_vec[grid[i][j]] = {getVal(adj_vec, i, j),
                                     getVal(dia_vec, i, j)};
            }
        }
    }

    int adjacentSum(int value) { return m_vec[value].first; }

    int diagonalSum(int value) { return m_vec[value].second; }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> grid{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    NeighborSum obj(grid);
    cout << obj.adjacentSum(1) << endl; // 6
    cout << obj.adjacentSum(4) << endl; // 16
    cout << obj.diagonalSum(4) << endl; // 16
    cout << obj.diagonalSum(8) << endl; // 4

    return 0;
}
