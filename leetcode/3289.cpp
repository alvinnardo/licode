#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> getSneakyNumbers(vector<int> &&nums) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(1)

    // 用原数组当哈希表
    int sz = nums.size();
    int tmp{};
    vector<int> res;
    for (int num : nums) {
        tmp = num % sz;

        if (nums[tmp] / sz == 1) {
            res.push_back(tmp);
            if (res.size() == 2) {
                break;
            }
        } else {
            nums[tmp] += sz;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {0,1}
    cout << getSneakyNumbers({0, 1, 1, 0}) << endl;
    // {2,3}
    cout << getSneakyNumbers({0, 3, 2, 1, 3, 2}) << endl;

    return 0;
}
