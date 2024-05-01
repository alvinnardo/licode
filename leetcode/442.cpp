#include "../template/head.h"
#include <bits/stdc++.h>
vector<int> findDuplicates(vector<int> nums) {
    // 优化：之前的解法是增加，看题解给出用正负做标记的方法
    // 时间 O(n), 空间 O(1)
    vector<int> res;
    for (auto &num : nums) {
        int t = abs(num);
        if (nums[t - 1] < 0) {
            res.push_back(t);
        } else {
            nums[t - 1] = -nums[t - 1];
        }
    }

    return res;
}

vector<int> findDuplicates1(vector<int> nums) {
    // 思路：哈希表
    // 要实现 O(1) 的空间，可以直接用原数组保存
    // 因为数字是 1 .. n 的，-1 后直接用原数组的 10^5 之后保存

    for (auto &num : nums) {
        // 这里注意要对 100000 取余，因为元素值被更改了
        nums[num % 100000 - 1] += 100000;
    }

    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 200000) { // 原元素是 >= 1 的
            res.push_back(i + 1);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // [2, 3]
    printVector(findDuplicates({4, 3, 2, 7, 8, 2, 3, 1}));
    // {1}
    printVector(findDuplicates({1, 1, 2}));
    // {}
    printVector(findDuplicates({}));
    // [2, 3]
    printVector(findDuplicates({2, 2, 3, 3, 1}));
    // [1, 3, 5]
    printVector(findDuplicates({5, 5, 3, 3, 1, 1}));

    return 0;
}
