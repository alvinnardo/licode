#include "../template/head.h"
#include <bits/stdc++.h>

int countCompleteSubarrays(vector<int> nums) {
    // 思路：双指针
    // 时间 O(n)，空间 O(k)，k 是不同数字的个数

    // 先统计所有的，得到所有不同的个数
    unordered_set<int> uset1;
    unordered_map<int, int> umap;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        uset1.insert(nums[i]);
    }

    // 如果满足，则外面都满足
    int m = uset1.size();
    int j = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        umap[nums[i]]++;

        while (umap.size() == m) {

            cnt += n - i;

            if (--umap[nums[j]] == 0) {
                umap.erase(nums[j]);
            }
            j++;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 4
    cout << countCompleteSubarrays({1, 3, 1, 2, 2}) << endl;
    // 10
    cout << countCompleteSubarrays({5, 5, 5, 5}) << endl;

    return 0;
}
