#include "../template/head.h"
#include <bits/stdc++.h>

string answerString(string word, int numFriends) {
    // 思路：滑动窗口
    // 时间 O(mn)，空间 O(n)

    // 主要需要理解题目意思
    // 剩下的朋友最少有一个
    // 所以字典序最大可以从任何一个位置开始

    if (numFriends == 1) { // 1 个的不能拆
        return word;
    }

    int len = word.size();
    vector<int> pos_vec(len), tmp_vec;

    // 准备，保存可行串的开始位置
    // 所有串都可行
    iota(pos_vec.begin(), pos_vec.end(), 0);

    int maxv = INT_MIN, t = 0;
    int up = len - numFriends + 1; // 剩下最少有一个，所以有上限
    for (int i = 0; i < (len - numFriends + 1); i++) {
        tmp_vec.clear();
        maxv = INT_MIN;
        for (int j = 0; j < pos_vec.size(); j++) {
            if (pos_vec[j] + i >= len) { // 超了就舍弃
                continue;
            }

            t = word[pos_vec[j] + i] - 'a';
            if (t == maxv) {
                tmp_vec.push_back(pos_vec[j]);
            } else if (t > maxv) {
                maxv = t;
                tmp_vec.clear();
                tmp_vec.push_back(pos_vec[j]);
            }
        }

        pos_vec = tmp_vec;
        if (pos_vec.size() == 1) { // 只有一个最大的就可以终止了
            break;
        }
    }

    // 如果在上限的情况下超过结尾，则只截取上限长度的字符串
    if (pos_vec[0] + up - 1 < len) {
        return word.substr(pos_vec[0], up);
    }
    return word.substr(pos_vec[0]);
}

int main(int argc, char *argv[]) {
    // "dbc"
    cout << answerString("dbca", 2) << endl;
    // "dbca"
    cout << answerString("dbca", 1) << endl;
    // "gh"
    cout << answerString("gh", 1) << endl;
    // "g"
    cout << answerString("gggg", 4) << endl;
    // "vogcvco"
    cout << answerString("ouabvogcvco", 5) << endl;

    return 0;
}
