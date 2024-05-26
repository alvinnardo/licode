#include "../template/head.h"
#include <bits/stdc++.h>
int kthLargestValue(vector<vector<int>> matrix, int k) {
    // 题解：快速选择
    // 这种算法就需要空间来保存了
    // 时间 O(mn)，空间 O(mn)
    vector<int> vec;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int t = matrix[i][j];
            if (i - 1 >= 0) {
                t ^= matrix[i - 1][j];
            }
            if (j - 1 >= 0) {
                t ^= matrix[i][j - 1];
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                t ^= matrix[i - 1][j - 1];
            }

            matrix[i][j] = t;

            vec.push_back(t);
        }
    }

    nth_element(vec.begin(), vec.begin() + k - 1, vec.end(), greater<int>());
    return vec[k - 1];
}

int kthLargestValue_my(vector<vector<int>> matrix, int k) {
    // 思路：优先队列
    // 当前元素值 = 当前元素值 ^ 上面异或和 ^ 左面异或和 ^ 左上异或和
    // 时间 O(mnlogmn)，空间 O(1)
    priority_queue<int, vector<int>, greater<int>> pq;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int t = matrix[i][j];
            if (i - 1 >= 0) {
                t ^= matrix[i - 1][j];
            }
            if (j - 1 >= 0) {
                t ^= matrix[i][j - 1];
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                t ^= matrix[i - 1][j - 1];
            }

            matrix[i][j] = t;

            pq.push(t);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    return pq.top();
}

int main(int argc, char *argv[]) {
    // 7
    cout << kthLargestValue({{5, 2}, {1, 6}}, 1) << endl;
    // 5
    cout << kthLargestValue({{5, 2}, {1, 6}}, 2) << endl;
    // 4
    cout << kthLargestValue({{5, 2}, {1, 6}}, 3) << endl;
    // 0
    cout << kthLargestValue({{5, 2}, {1, 6}}, 4) << endl;

    return 0;
}
