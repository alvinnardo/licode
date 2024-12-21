#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> sortTheStudents(vector<vector<int>> score, int k) {
    // 思路：排序
    // 时间 O(mlogm)，空间 O(logm)
    sort(score.begin(), score.end(),
         [&](vector<int> &a, vector<int> &b) { return a[k] > b[k]; });

    return score;
}

int main(int argc, char *argv[]) {
    // {{7,5,11,2},{10,6,9,1},{4,8,3,15}}
    printVectorVector(
        sortTheStudents({{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}}, 2));
    // {{5,6},{3,4}}
    printVectorVector(sortTheStudents({{3, 4}, {5, 6}}, 0));

    return 0;
}
