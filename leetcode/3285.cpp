#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> stableMountains(vector<int> height, int threshold) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    vector<int> res;
    for (int i = 1; i < height.size(); i++) {
        if (height[i - 1] > threshold) {
            res.emplace_back(i);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {3,4}
    printVector(stableMountains({1, 2, 3, 4, 5}, 2));
    // {1,3}
    printVector(stableMountains({10, 1, 10, 1, 10}, 3));
    // {}
    printVector(stableMountains({10, 1, 10, 1, 10}, 10));

    return 0;
}
