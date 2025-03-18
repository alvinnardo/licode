#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> splitIntoFibonacci(string num) {
    // 思路：回溯
    // 时间 O(nlogC*logC)，空间 O(n)
    // 主要在剪枝上节省时间

    // *** 时间复杂度我认为是 O(n!)，剪枝优化常数时间
    // 但看了题解，只有前两个数用于铺底，然后的只要验证，不需要全部枚举
    // 第一个数是 log_10(C)，第二个数是 log_10(C)，
    // 后面的数只验证返回，为 O(n)
    // 总的时间复杂度是 O(nlogC*logC)

    vector<int> res, tmp;
    int len = num.length();

    function<void(int)> dfs = [&](int pos) {
        if (pos == len) {
            if (tmp.size() > 2) {
                res = tmp;
            }
            return;
        }

        long long t = 0;
        for (int i = pos; i < len; i++) {
            if (i == pos + 1 && t == 0) { // 不能 0 开头
                break;
            }

            t = t * 10 + (num[i] - '0');
            if (t > INT_MAX) {
                break;
            }
            if (tmp.size() < 2) {
                tmp.push_back(t);
                dfs(i + 1);
                tmp.pop_back();
            } else {
                long long bak = (long long)tmp[tmp.size() - 2] + tmp.back();
                if (bak > INT_MAX) {
                    break;
                }
                if (t == bak) {
                    tmp.push_back(t);
                    dfs(i + 1);
                    tmp.pop_back();
                } else if (t > bak || t == 0) { // t < bak && t == 0 不能继续了
                    break;
                }
            }
            if (!res.empty()) {
                break;
            }
        }
    };

    dfs(0);
    return res;
}

int main(int argc, char *argv[]) {
    // {11,0,11,11}
    printVector(splitIntoFibonacci("1101111"));
    // {}
    printVector(splitIntoFibonacci("112358130"));
    // {}
    printVector(splitIntoFibonacci("0123"));
    // {123, 456, 579}
    printVector(splitIntoFibonacci("123456579"));
    return 0;
}
