#include "../template/head.h"
#include <bits/stdc++.h>

string addSpaces(string s, vector<int> spaces) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int j = 0, len = s.length();
    string res;
    for (int i = 0; i < len; i++) {
        // 在当前下标检查一下
        if (j < spaces.size() && i == spaces[j]) {
            res += ' ';
            j++;
        }

        res += s[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "Leetcode Helps Me Learn"
    cout << addSpaces("LeetcodeHelpsMeLearn", {8, 13, 15}) << endl;
    // "i code in py thon"
    cout << addSpaces("icodeinpython", {1, 5, 7, 9}) << endl;
    // " s p a c i n g"
    cout << addSpaces("spacing", {0, 1, 2, 3, 4, 5, 6}) << endl;

    return 0;
}
