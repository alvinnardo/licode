#include "../template/head.h"
#include <bits/stdc++.h>
vector<int> pivotArray(vector<int> nums, int pivot) {
    // 题解：双指针
    // 时间 O(n)，空间 O(1)
    // 一次遍历优化，处理小于和大于的，最后把大于的翻转

    // 相等的不处理，所以都初始化为 pivot
    vector<int> res(nums.size(), pivot);

    int left = 0, right = nums.size() - 1;
    for (int num : nums) {
        if (num < pivot) {
            res[left++] = num;
        } else if (num > pivot) {
            res[right--] = num;
        }
    }

    if (right != nums.size() - 1) {
        reverse(res.begin() + right + 1, res.end());
    }

    return res;
}

vector<int> pivotArray1(vector<int> nums, int pivot) {
    // 思路：遍历
    // 由于交换，所以快排是不稳定的
    // 先遍历一遍，找小于和等于的个数，再用变量记录位置
    // 时间 O(n)，空间 O(1)
    int cnt1 = 0, cnt2 = 0;
    for (int num : nums) {
        cnt1 += num < pivot;
        cnt2 += num == pivot;
    }

    vector<int> res(nums.size());
    int pos1 = 0, pos2 = cnt1, pos3 = cnt1 + cnt2;
    for (int num : nums) {
        if (num < pivot) {
            res[pos1++] = num;
        } else if (num == pivot) {
            res[pos2++] = num;
        } else {
            res[pos3++] = num;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {9,5,3,10,10,12,14}
    printVector(pivotArray({9, 12, 5, 10, 14, 3, 10}, 10));
    // {-3,2,4,3}
    printVector(pivotArray({-3, 4, 3, 2}, 2));

    return 0;
}
