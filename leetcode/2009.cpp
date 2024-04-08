#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> nums) {
    // 1. 排序 + 去重
    // 2. 双指针，找到圈住的大小

    sort(nums.begin(), nums.end());

    int sz = nums.size();

    vector<int> single_vec;
    single_vec.push_back(nums[0]);
    for (int i = 1; i < sz; i++) {
        if (nums[i] != nums[i - 1]) {
            single_vec.push_back(nums[i]);
        }
    }

    // 每个元素当一次头部 head，右指针指向 head + sz;
    int maxv = INT_MIN;
    int new_sz = single_vec.size();

    int j = 0;
    for (int i = 0; i < new_sz; i++) {
        // 找严格大于的
        while (j < new_sz && single_vec[j] <= single_vec[i] + sz - 1) {
            j++;
        }

        maxv = max(j - i, maxv); // (j - 1) - i + 1 = j - i
    }

    return sz - maxv;
}

int main(void) {

    cout << minOperations({4, 2, 5, 3}) << endl;
    cout << minOperations({1, 2, 3, 5, 6}) << endl;
    cout << minOperations({1, 10, 100, 1000}) << endl;
    cout << minOperations({1}) << endl;
    cout << minOperations({1,1,1,1,1}) << endl;
    vector<int> tmp = getNRandom(10, 100, 10000);
    printVector(tmp);
    cout << minOperations(tmp) << endl;


    return 0;
}
