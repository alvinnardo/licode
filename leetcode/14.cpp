#include "../template/head.h"
#include <bits/stdc++.h>

string longestCommonPrefix(vector<string> &&strs) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    if (strs.empty()) {
        return "";
    }
    int sz = strs.size();

    string res = strs[0], tmp;
    for (int i = 1; i < sz; ++i) {
        tmp.clear();
        for (int j = 0; j < res.length() && j < strs[i].length(); ++j) {
            if (res[j] == strs[i][j]) {
                tmp += res[j];
            } else {
                break;
            }
        }

        res = tmp;
        if (res.empty()) {
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "fl"
    cout << longestCommonPrefix({"flower", "flow", "flight"}) << endl;
    // ""
    cout << longestCommonPrefix({"dog", "racecar", "car"}) << endl;
    // "c"
    cout << longestCommonPrefix({"cir", "car"}) << endl;

    return 0;
}
