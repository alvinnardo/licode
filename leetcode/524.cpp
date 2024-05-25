#include "../template/head.h"
#include <bits/stdc++.h>

string findLongestWord(string s, vector<string> dictionary) {
    // 题解：序列自动机(DP)
    // 对匹配符做预处理，对于每个字符，找到后面字符第一次出现的位置
    // 时间: O(m * 26 + n * d)，d 是字典中字符串的平均长度

    int len = s.length();
    vector<vector<int>> dp(len, vector<int>(26));
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (!dp[i][s[j] - 'a']) {
                dp[i][s[j] - 'a'] = j;
            }
        }
    }

    string res;
    for (auto &str : dictionary) {
        if (str.length() > s.length()) {
            continue;
        }

        int i = 0, j = 0;
        while (i < s.length() && j < str.length()) {
            if (s[i] == str[j]) {
                i++;
                j++;
            } else {
                int char_pos = str[j] - 'a';
                if (dp[i][char_pos] == 0) {
                    break;
                } else {
                    i = dp[i][char_pos];
                }
            }
        }

        if (j == str.length()) {
            // cout << str << endl;
            if (str.length() > res.length()) {
                res = str;
            } else if (str.length() == res.length() && str < res) {
                res = str;
            }
        }
    }

    return res;
}

string findLongestWord_my(string s, vector<string> dictionary) {
    // 思路：贪心
    // 时间 O(nlogn + n*l)，空间 O(1)
    // 先排序，如果长度相等，则字典序小的在前面，否则长度长的在前面
    sort(dictionary.begin(), dictionary.end(),
         [](const std::string &a, const std::string &b) {
             return a.length() == b.length() ? a < b : a.length() > b.length();
         });

    for (auto &str : dictionary) {
        int pos = 0;
        for (int i = 0; i < s.length(); i++) {
            if (pos < str.length() && str[pos] == s[i]) {
                pos++;
            }

            if (pos == str.length()) {
                return str;
            }
        }
    }

    return "";
}

int main(int argc, char *argv[]) {
    // "apple"
    cout << findLongestWord("abpcplea", {"ale", "apple", "monkey", "plea"})
         << endl;
    // "a"
    cout << findLongestWord("abpcplea", {"a", "b", "c"}) << endl;
    // ""
    cout << findLongestWord("abpcplea", {"aec"}) << endl;

    return 0;
}
