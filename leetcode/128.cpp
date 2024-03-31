#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> nums) {

    // 官方题解：哈希表 (间接去重)
    unordered_set<int> uset(nums.begin(), nums.end());
    int max_len = 0, tlen = 0;
    // 因为跳过，所以是 O(n) 的
    for (auto &i : uset) { // 如果是起始点，就开始计数，否则跳过
        if (uset.find(i - 1) != uset.end()) {
            continue;
        } else {
            tlen = 1;
            max_len = max(max_len, tlen);

            int t = i;
            while (uset.find(t + 1) != uset.end()) {
                t++;
                tlen++;
            }
            max_len = max(max_len, tlen);
        }
    }
    return max_len;
}

void radixSort(vector<int> &nums) {

    long long mod = 10, div = 1;
    // 当 cnt 等于数组大小时，就不进行下一轮，最高位都是 0 了
    int cnt = 0;

    vector<queue<int>> vec(10);
    while (cnt != nums.size()) {
        cnt = 0;

        for (auto &i : nums) {
            int t = (i % mod) / div;
            vec[t].push(i);
            if (i / div == 0) {
                cnt++;
            }
        }

        mod *= 10;
        div *= 10;

        int idx = 0;
        for (int i = 0; i < 10; i++) {
            while (!vec[i].empty()) {
                int t = vec[i].front();
                vec[i].pop();
                nums[idx++] = t;
            }
        }
    }
}

int longestConsecutive_my(vector<int> nums) {
    if (nums.size() == 0)
        return 0;
    // 1. 使用基数排序
    // 2. 求最长序列
    vector<int> nums_neg, nums_posi;
    for (auto &i : nums) {
        if (i < 0) {
            nums_neg.push_back(-i);
        } else {
            nums_posi.push_back(i);
        }
    }
    radixSort(nums_neg);
    radixSort(nums_posi);

    vector<int> tvec; // 去重
    for (int i = nums_neg.size() - 1; i >= 0; i--) {
        if (i < nums_neg.size() - 1 && nums_neg[i] == nums_neg[i + 1]) {
            continue;
        }
        tvec.push_back(-nums_neg[i]);
    }

    for (int i = 0; i < nums_posi.size(); i++) {
        if (i > 0 && nums_posi[i] == nums_posi[i - 1]) {
            continue;
        }
        tvec.push_back(nums_posi[i]);
    }

    printVector(tvec);
    int max_len = 1, tlen = 1;
    for (int i = 1; i < tvec.size(); i++) {
        if (tvec[i] - tvec[i - 1] == 1) {
            tlen++;
        } else {
            tlen = 1;
        }
        max_len = max(max_len, tlen);
    }

    return max_len;
}

int main(void) {
    cout << longestConsecutive({100, 4, 200, 1, 3, 2}) << endl;         // 4
    cout << longestConsecutive({110, 10, 120}) << endl;                 // 1
    cout << longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}) << endl; // 9
    cout << longestConsecutive({-1000000000, -11, -10, -3, -2, -1, 0, 3, 7, 2,
                                5, 8, 4, 6, 0, 1})
         << endl;                                     // 12
    cout << longestConsecutive({}) << endl;           // 0
    cout << longestConsecutive({1, 2, 0, 1}) << endl; // 3

    return 0;
}
