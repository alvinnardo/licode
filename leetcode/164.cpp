#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

void radix_sort(vector<int> &nums) {
    vector<queue<int>> vec(10);
    long long mod = 10, div = 1;
    int cnt = 0;
    while (cnt != nums.size()) {
        cnt = 0;
        long long ndiv = div * 10;

        for (int i = 0; i < nums.size(); i++) { // 放
            if (nums[i] / ndiv == 0) {
                cnt++;
            }

            int t = (nums[i] % mod) / div;
            vec[t].push(nums[i]);
        }

        int idx = 0;
        for (int i = 0; i < 10; i++) { // 取
            while (!vec[i].empty()) {
                nums[idx++] = vec[i].front();
                vec[i].pop();
            }
        }

        mod *= 10; // 扩大
        div *= 10;
    }
}

int maximumGap(vector<int> nums) {
    // 思路：基数排序 + 最后一遍扫描
    int sz = nums.size();
    if (sz < 2)
        return 0;

    radix_sort(nums);
    printVector(nums);
    int maxv = INT_MIN;
    for (int i = 1; i < nums.size(); i++) {
        maxv = max(maxv, nums[i] - nums[i - 1]);
    }
    return maxv;
}

int main(void) {
    cout << maximumGap({3, 6, 9, 1}) << endl;
    cout << maximumGap({10}) << endl;
    cout << maximumGap({10, 10}) << endl;
    cout << maximumGap({10, 10, 20}) << endl;
    cout << maximumGap({0, 10, 21}) << endl;
    cout << maximumGap({0, 0, 100000000}) << endl;
    cout << maximumGap({1000000000, 0, 100000000}) << endl;

    return 0;
}
