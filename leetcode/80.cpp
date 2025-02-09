#include "../template/head.h"
#include <bits/stdc++.h>

int removeDuplicates(vector<int> nums) {
    // 思路：双指针
    // 时间 O(n)，空间 O(1)
    int i = 0, j = 0, sz = nums.size();
    int pre = INT_MIN, cnt = 0;

    // j 用来遍历数组，i 用来标记结果最后的位置
    // 因为 j 会遍历所有，将 while 改用 for 循环
    for (int j = 0; j < sz; j++) {
        if (nums[j] == pre) {
            cnt++;
        } else {
            pre = nums[j];
            cnt = 1;
        }

        if (cnt <= 2) {
            nums[i++] = nums[j];
        }
    }

    // 不用 resize，会根据返回结果打印
    return i;
}

int main(int argc, char *argv[]) {

    // 5
    cout << removeDuplicates({1, 1, 1, 2, 2, 3}) << endl;
    // 7
    cout << removeDuplicates({0, 0, 1, 1, 1, 1, 2, 3, 3}) << endl;
    // 7
    cout << removeDuplicates({0, 0, 1, 1, 2, 3, 3}) << endl;

    return 0;
}
