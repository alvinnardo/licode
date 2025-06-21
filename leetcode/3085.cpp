#include "../template/head.h"
#include <bits/stdc++.h>

int minimumDeletions(string word, int k) {
    // 思路：统计 + 贪心
    // 时间 O(n + s2)，空间 O(s)
    // 先统计每个字符的个数，再模拟固定最大值遍历最小值
    vector<int> vec(26);
    for (auto &c : word) {
        vec[c - 'a']++;
    }

    vector<int> vec2;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i]) {
            vec2.push_back(vec[i]);
        }
    }

    sort(vec2.begin(), vec2.end());
    // 依次遍历最小值，找到符合条件的最大值，把多的地方截掉
    int minv = INT_MAX;
    for (int i = 0; i < vec2.size(); i++) {
        int t = vec2[i];
        for (int j = i + 1; j < vec2.size(); j++) {
            if (vec2[j] - vec2[i] > k) {
                t += vec2[i] + k;
            } else {
                t += vec2[j];
            }
        }
        minv = min(minv, (int)word.length() - t);
    }

    return minv;
}

int main(int argc, char *argv[]) {
    // 3
    cout << minimumDeletions("aabcaba", 0) << endl;
    // 2
    cout << minimumDeletions("dabdcbdcdcd", 2) << endl;
    // 1
    cout << minimumDeletions("aaabaaa", 2) << endl;

    return 0;
}
