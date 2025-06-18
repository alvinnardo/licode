#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> divideArray(vector<int> &&nums, int k) {
    // 思路：排序 + 贪心
    // 时间 O(nlogn)，空间 O(1)
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for (int i = 1; i < nums.size(); i += 3) {
        if (nums[i + 1] - nums[i - 1] <= k) {
            res.push_back({nums[i - 1], nums[i], nums[i + 1]});
        } else {
            return {};
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {{1,1,3},{3,4,5},{7,8,9}}
    printVectorVector(divideArray({1, 3, 4, 8, 7, 9, 3, 5, 1}, 2));
    // {}
    printVectorVector(divideArray({2, 4, 2, 2, 5, 2}, 2));
    // {{2,2,12},{4,8,5},{5,9,7},{7,8,5},{5,9,10},{11,12,2}}
    printVectorVector(divideArray(
        {4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11}, 14));

    return 0;
}
