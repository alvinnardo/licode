#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

// n 为操作数个数，包括数字和运算符
// 时间 O(2^n)
// 空间 O(2^n)
vector<int> diffWaysToCompute(string expression) {

    function<vector<int>(int, int)> dfs =
        [&](int bng, int end) -> vector<int> { // 左右闭
        // 数字在 0 - 99
        int len = end - bng + 1;
        if (len == 1) {
            int t = expression[bng] - '0';
            return {t};
        }
        if (len == 2) {
            int t = (int)(expression[bng] - '0') * 10 + (expression[end] - '0');
            return {t};
        }

        vector<int> res, left, right;
        for (int i = bng; i <= end; i++) {
            left.clear();
            right.clear();
            if (expression[i] == '-' || expression[i] == '+' ||
                expression[i] == '*') {
                left = std::move(dfs(bng, i - 1));
                right = std::move(dfs(i + 1, end));

                for (int p = 0; p < left.size(); p++) {
                    for (int q = 0; q < right.size(); q++) {
                        if (expression[i] == '-') {
                            res.push_back(left[p] - right[q]);
                        } else if (expression[i] == '+') {
                            res.push_back(left[p] + right[q]);
                        } else {
                            res.push_back(left[p] * right[q]);
                        }
                    }
                }
            }
        }

        return res;
    };

    return dfs(0, expression.size() - 1);
}

int main(void) {
    // [0, 2]
    printVector(diffWaysToCompute("2-1-1"));
    // [-34, -14, -10, -10, 10]
    printVector(diffWaysToCompute("2*3-4*5"));
    printVector(diffWaysToCompute("0*19-20+55*2-99*3-10"));
    printVector(diffWaysToCompute("33"));
    printVector(diffWaysToCompute("3"));

    return 0;
}
