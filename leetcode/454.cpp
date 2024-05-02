#include "../template/head.h"
#include <bits/stdc++.h>
int fourSumCount(vector<int> nums1, vector<int> nums2, vector<int> nums3,
                 vector<int> nums4) {
    // 优化，一个哈希表即可
    unordered_map<int64_t, int> sum12;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            int64_t t = nums1[i] + nums2[j];
            sum12[t]++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < nums3.size(); i++) {
        for (int j = 0; j < nums4.size(); j++) {
            int64_t t = -nums3[i] - nums4[j];
            if (sum12.find(t) != sum12.end()) {
                cnt += sum12[t];
            }
        }
    }

    return cnt;
}

int fourSumCount1(vector<int> nums1, vector<int> nums2, vector<int> nums3,
                  vector<int> nums4) {
    // 思路：哈希表，先合并，再判断
    // 时间 O(n2), 空间 O(n2)
    unordered_map<int64_t, int> sum12, sum34;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            int64_t t = nums1[i] + nums2[j];
            sum12[t]++;
        }
    }
    for (int i = 0; i < nums3.size(); i++) {
        for (int j = 0; j < nums4.size(); j++) {
            int64_t t = nums3[i] + nums4[j];
            sum34[t]++;
        }
    }

    int cnt = 0;
    for (auto &it : sum12) {
        int64_t t = -it.first;
        if (sum34.find(t) != sum34.end()) {
            cnt += it.second * sum34[t];
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    cout << fourSumCount({1, 2}, {-2, -1}, {-1, 2}, {0, 2}) << endl;
    cout << fourSumCount({0}, {0}, {0}, {0}) << endl;

    return 0;
}
