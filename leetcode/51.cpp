#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<string>> solveNQueens(int n) {
    // 思路：回溯法
    // 后续可以使用位运算进行优化
    // 时间 O(n!)，空间 O(n)

    if (n == 2 || n == 3) {
        return {};
    }
    vector<vector<string>> res;
    vector<int> vec;

    string tmp(n, '.');
    auto getRes = [&]() {
        vector<string> vv;
        for (int i : vec) {
            tmp[i] = 'Q';
            vv.emplace_back(tmp);
            tmp[i] = '.';
        }

        res.emplace_back(vv);
    };

    unordered_set<int> uset;
    for (int i = 0; i < n; i++) {
        uset.insert(i);
    }

    function<void()> func = [&]() {
        if (vec.size() == n) {
            getRes();
            return;
        }

        auto tset = uset;
        for (int i : tset) {
            bool can_put = true;
            for (int j = 0; j < vec.size(); j++) {
                // j 是行号，vec[j] 是列号
                // vec.size() 是当前的行号，i 是尝试当前的列号
                int col_diff = i - vec[j], row_diff = vec.size() - j;
                if (abs(col_diff) == abs(row_diff)) {
                    can_put = false;
                    break;
                }
            }

            if (can_put) {
                uset.erase(i);
                vec.push_back(i);
                func();
                vec.pop_back();
                uset.insert(i);
            }
        }
    };

    func();
    return res;
}

int main(int argc, char *argv[]) {
    // {{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}}
    printVectorVector(solveNQueens(4));
    // {{"Q"}}
    printVectorVector(solveNQueens(1));
    printVectorVector(solveNQueens(9));

    return 0;
}
