#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

int longestSubstring(string s, int k) {
    // 思路
    // 1. 统计所有字符出现的次数
    // 2. 找到最中间不合法的字符
    // 3. 递归左右子字符串
    // 时间 O(nlogn)
    if (k == 1) {
        return s.length();
    }

    if (s.length() < k) {
        return 0;
    }

    function<int(int, int)> dfs = [&](int l, int r) {
        if (l > r || r - l + 1 < k) {
            return 0;
        }

        unordered_map<char, int> umap;
        unordered_set<char> uset;
        for (int i = l; i <= r; i++) {
            if (++umap[s[i]] >= k) {
                uset.insert(s[i]);
            }
        }

        // 字符都满足条件
        if (umap.size() == uset.size()) {
            return r - l + 1;
        }

        // 用距离中间最近的不满足字符进行分隔
        int minv = INT_MAX, mid = l + ((r - l) >> 1);
        int pos = mid;
        for (int i = l; i <= r; i++) {
            if (uset.find(s[i]) == uset.end()) {
                int t = abs(i - mid);
                if (t < minv) {
                    minv = t;
                    pos = i;
                }
            }
        }

        return max(dfs(l, pos - 1), dfs(pos + 1, r));
    };

    return dfs(0, s.length() - 1);
}

int main(void) {
    // 4
    cout << longestSubstring("ababcdefg", 2) << endl;
    // 4
    cout << longestSubstring("cdeababfg", 2) << endl;
    // 4
    cout << longestSubstring("cdefgabba", 2) << endl;
    // 3
    cout << longestSubstring("aaabb", 3) << endl;
    // 5
    cout << longestSubstring("ababbc", 2) << endl;
    // 0
    cout << longestSubstring("abcdefghijklmnopqrstuvwxyz", 2) << endl;
    // 30
    cout << longestSubstring("llllljjcjjaacbedadbcedaaaaceblklnlklk", 3)
         << endl;
    // 0
    cout << longestSubstring("llllljjcjjaacbedadbcedaaaaceblklnlklk", 10000)
         << endl;

    return 0;
}
