#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> lexicalOrder(int n) {
    // 思路：迭代
    // 时间 O(n)，空间 O(1)
    vector<int> res(n);
    int num = 1;

    int cnt = 0;
    for (int i = 0; i < res.size(); i++) {
        res[i] = num;

        if (num * 10 <= n) { // 是否还有下一层
            num *= 10;
        } else {
            // 结尾多个 9，返回多层
            while (num % 10 == 9 || num + 1 > n) {
                num /= 10;
            }

            num++;
        }
    }

    return res;
}

vector<int> lexicalOrder1(int n) {
    // 思路：DFS
    // 时间 O(n)，空间 O(logn)
    vector<int> res;

    function<void(int)> dfs = [&](int top) {
        top *= 10;
        int t = 0;
        for (int i = 0; i < 10; i++) {
            t = top + i;
            if (t > n) {
                break;
            }
            if (t == 0) {
                continue;
            }

            res.push_back(top + i);
            dfs(top + i);
        }
    };

    dfs(0);
    return res;
}

int main(int argc, char *argv[]) {
    // {1,10,11,12,13,2,3,4,5,6,7,8,9}
    printVector(lexicalOrder(13));
    // {1,2}
    printVector(lexicalOrder(2));

    return 0;
}
