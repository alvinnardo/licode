#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> asteroidCollision(vector<int> asteroids) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    vector<int> res;

    for (auto &as : asteroids) {
        while (!res.empty() && res.back() > 0 && as < 0 &&
               abs(as) > abs(res.back())) {
            res.pop_back();
        }

        // 判断是否被摧毁
        if (!res.empty() && res.back() > 0 && as < 0 &&
            abs(as) <= abs(res.back())) {
            if (abs(as) == abs(res.back())) {
                res.pop_back();
            }
            continue;
        }

        res.push_back(as);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {5,10}
    printVector(asteroidCollision({5, 10, -5}));
    // {}
    printVector(asteroidCollision({8, -8}));
    // {10}
    printVector(asteroidCollision({10, 2, -5}));
    return 0;
}
