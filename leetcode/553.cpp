#include "../template/head.h"
#include <bits/stdc++.h>

string optimalDivision(vector<int> nums) {
    // 思路：数学，分子要最大，分母要最小
    // 单独考虑个数为 1 和 2 的情况
    int sz = nums.size();
    if (sz == 1) {
        return to_string(nums[0]);
    } else if (sz == 2) {
        return to_string(nums[0]) + "/" + to_string(nums[1]);
    }

    string res;
    for (int i = 0; i < nums.size(); i++) {
        res += to_string(nums[i]);
        if (i == 0) {
            res += "/(";
        } else if (i == nums.size() - 1) {
            res += ")";
        } else {
            res += "/";
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "3"
    cout << optimalDivision({3}) << endl;
    // "2/3"
    cout << optimalDivision({2, 3}) << endl;
    // "1000/(100/10/2)"
    cout << optimalDivision({1000, 100, 10, 2}) << endl;
    // "2/(3/4)"
    cout << optimalDivision({2, 3, 4}) << endl;

    return 0;
}
