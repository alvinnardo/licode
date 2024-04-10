#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
  public:
    vector<vector<int>> m_matrix;
    NumMatrix(vector<vector<int>> &matrix) : m_matrix(matrix) {
        int m = m_matrix.size(), n = m_matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = i - 1 >= 0 ? m_matrix[i - 1][j] : 0;
                int left = j - 1 >= 0 ? m_matrix[i][j - 1] : 0;
                int cor = i - 1 >= 0 && j - 1 >= 0 ? m_matrix[i - 1][j - 1] : 0;

                m_matrix[i][j] += up + left - cor;
            }
        }

        // printVectorVector(matrix);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int up = row1 - 1 >= 0 ? m_matrix[row1 - 1][col2] : 0;
        int left = col1 - 1 >= 0 ? m_matrix[row2][col1 - 1] : 0;
        int cor =
            row1 - 1 >= 0 && col1 - 1 >= 0 ? m_matrix[row1 - 1][col1 - 1] : 0;

        return m_matrix[row2][col2] - up - left + cor;
    }
};

int main(void) {
    vector<vector<int>> matrix{{3, 0, 1, 4, 2},
                               {5, 6, 3, 2, 1},
                               {1, 2, 0, 1, 5},
                               {4, 1, 0, 1, 7},
                               {1, 0, 3, 0, 5}};
    NumMatrix *obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << obj->sumRegion(1, 2, 2, 4) << endl;
    cout << obj->sumRegion(0, 0, 0, 0) << endl;
    cout << obj->sumRegion(1, 0, 4, 0) << endl;

    return 0;
}
