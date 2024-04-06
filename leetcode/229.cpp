#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> nums) {
    // 题解：摩尔投票法（打擂台战）
    // 一般用于求个数大于 floor(n/2) 个数的值，该值最多只有一个
    // 该题求解个数大于 floor(n/3) 个数的值，该值最多只有两个

    int element1 = 0, element2 = 0;
    int vote1 = 0, vote2 = 0;

    for (auto &num : nums) {
        if (vote1 > 0 && num == element1) {
            vote1++;
        } else if (vote2 > 0 && num == element2) {
            vote2++;
        } else if (vote1 == 0) { // 既不是 e1，也不是 e2，然后选择一个空阵营
            element1 = num;
            vote1++;
        } else if (vote2 == 0) {
            element2 = num;
            vote2++;
        } else { // 互相抵消一次
            vote1--;
            vote2--;
        }
    }

    // 最后检查留下来的个数是否满足要求
    int cnt1 = 0;
    int cnt2 = 0;
    for (auto &num : nums) {
        if (vote1 > 0 && num == element1) {
            cnt1++;
        } else if (vote2 > 0 && num == element2) {
            cnt2++;
        }
    }

    vector<int> res;
    int threshold = nums.size() / 3;
    if (vote1 > 0 && cnt1 > threshold) {
        res.push_back(element1);
    }
    if (vote2 > 0 && cnt2 > threshold) {
        res.push_back(element2);
    }

    return res;
}

// 时间 O(n), 空间 O(n)
vector<int> majorityElement_my(vector<int> nums) {
    int sz = nums.size();
    int threshold = sz / 3;
    unordered_map<int, int> umap;
    for (int i = 0; i < sz; i++) {
        umap[nums[i]]++;
    }

    vector<int> res;
    for (auto &t : umap) {
        if (t.second > threshold) {
            res.push_back(t.first);
        }
    }
    return res;
}

int main(void) {
    printVector(majorityElement({3, 2, 3}));
    printVector(majorityElement({1}));
    printVector(majorityElement({1, 2}));
    printVector(majorityElement({4, 2, 1, 1}));

    return 0;
}
