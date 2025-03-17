#include "../template/head.h"
#include <bits/stdc++.h>

class CustomFunction {
  public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    // int f(int x, int y) { return x + y; }
    int f(int x, int y) { return x * y; }
};

class Solution {
  public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        // 思路：二分
        // 时间 O(klogk)，空间 O(1)
        // 因为题目给出是递增的，可以使用二分
        vector<vector<int>> res;
        for (int i = 1; i <= 1000; i++) {
            int left = 1, right = 1000;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                int t = customfunction.f(i, mid);
                if (t == z) {
                    res.push_back({i, mid});
                    break;
                } else if (t > z) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {

    CustomFunction cf;
    Solution solution;
    printVectorVector(solution.findSolution(cf, 5));

    return 0;
}
