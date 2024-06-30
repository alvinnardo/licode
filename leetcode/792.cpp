#include "../template/head.h"
#include <bits/stdc++.h>

int numMatchingSubseq(string s, vector<string> words) {
    // 思路：贪心 + 二分，先对字符串做预处理，把每个字符的位置列出来
    // 查找的时候用二分
    // 时间 O(n + mklogp)，空间 O(n)
    // n 是 s 的长度，m 是 words 长度，
    // k 是 words[i] 平均长度，p 是 s 中各类字符的平均个数

    vector<vector<int>> alpha_pos(26);
    for (int i = 0; i < s.length(); i++) {
        alpha_pos[s[i] - 'a'].push_back(i);
    }

    int cnt = 0;
    for (auto &word : words) {
        int cur_pos = -1;
        bool is_valid = true;
        for (int i = 0; i < word.length(); i++) {
            auto &vec = alpha_pos[word[i] - 'a'];
            // 二分查找位置
            auto pos = upper_bound(vec.begin(), vec.end(), cur_pos);
            if (pos == vec.end()) {
                is_valid = false;
                break;
            }
            cur_pos = *pos;
        }

        cnt += is_valid;
    }

    return cnt;
}

int main(int argc, char *argv[]) {

    // 3
    cout << numMatchingSubseq("abcde", {"a", "bb", "acd", "ace"}) << endl;
    // 2
    cout << numMatchingSubseq("dsahjpjauf",
                              {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"})
         << endl;

    return 0;
}
