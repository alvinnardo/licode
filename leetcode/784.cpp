#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<string> letterCasePermutation_my(const std::string &str) {
    std::string s = str;

    // 先将字母的位置保存下来
    vector<string> res;
    vector<int> pos_vec;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
            pos_vec.push_back(i);
        }
    }

    int len = pos_vec.size();
    function<void(int)> dfs = [&](int idx) {
        if (idx == len) {
            res.emplace_back(s);
            return;
        }

        dfs(idx + 1);
        int pos = pos_vec[idx];
        if (s[pos] >= 'a' && s[pos] <= 'z') {
            s[pos] += ('A' - 'a');
        } else if (s[pos] >= 'A' && s[pos] <= 'Z') {
            s[pos] += ('a' - 'A');
        }
        dfs(idx + 1);
        if (s[pos] >= 'a' && s[pos] <= 'z') {
            s[pos] += ('A' - 'a');
        } else if (s[pos] >= 'A' && s[pos] <= 'Z') {
            s[pos] += ('a' - 'A');
        }
    };

    dfs(0);
    return res;
}

vector<string> letterCasePermutation(const std::string &str) {
    std::string s = str;

    // 先将字母的位置保存下来
    vector<string> res;

    int len = s.length();
    function<void(int)> dfs = [&](int pos) {
        // 上来先判断，直到到达 length
        // 如果先判断 len，再判断是不是数字，当字符以数字结尾时答案就会重复
        while (pos < len && s[pos] >= '0' && s[pos] <= '9') {
            pos++;
        }
        if (pos == len) {
            res.emplace_back(s);
            return;
        }

        dfs(pos + 1);
        if (s[pos] >= 'a' && s[pos] <= 'z') {
            s[pos] += ('A' - 'a');
        } else if (s[pos] >= 'A' && s[pos] <= 'Z') {
            s[pos] += ('a' - 'A');
        }
        dfs(pos + 1);
        if (s[pos] >= 'a' && s[pos] <= 'z') {
            s[pos] += ('A' - 'a');
        } else if (s[pos] >= 'A' && s[pos] <= 'Z') {
            s[pos] += ('a' - 'A');
        }
    };

    dfs(0);
    return res;
}

int main(void) {
    printVector(letterCasePermutation("a1b22cc2"));
    printVector(letterCasePermutation("2"));
    printVector(letterCasePermutation("abc"));
    printVector(letterCasePermutation("2222"));
    printVector(letterCasePermutation("1b22c2232342a33334"));

    return 0;
}
