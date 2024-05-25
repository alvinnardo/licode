#include "../template/head.h"
#include <bits/stdc++.h>
int findLUSlength(vector<string> strs) {
    // 题解：脑筋急转弯，如果字符串中有特殊序列，那么特殊序列一定是串本身
    // 如果有特殊序列，那么在其中加入任何字符都是特殊序列，而串本身就是添加的一种结果
    // 所以对每个串，去和其它所有比它长的串进行比较，如果它不是其它串的子序列，
    // 那么它就是特殊序列
    // 时间 O(n2 * l)，空间 O(1)
    int sz = strs.size(), maxlen = 0;
    auto isSub = [&](int i, int j) { // 贪心
        int pos = 0;
        for (int a = 0; a < strs[j].length(); a++) {
            if (pos < strs[i].length() && strs[i][pos] == strs[j][a]) {
                pos++;
            }
        }

        return pos == strs[i].length();
    };

    for (int i = 0; i < sz; i++) {
        bool is = true; // 假设是特殊串序列

        for (int j = 0; j < sz; j++) {
            if (i == j) {
                continue;
            }

            // 如果比串短，不用判断
            if (strs[i].length() > strs[j].length()) {
                continue;
            }

            // 如果是其它的子序列，那么就不是特殊串序列
            if (isSub(i, j)) {
                is = false;
                break;
            }
        }

        if (is && strs[i].length() > maxlen) {
            maxlen = strs[i].length();
        }
    }

    return maxlen == 0 ? -1 : maxlen;
}

int findLUSlength_my(vector<string> strs) {
    // 思路：求所有子序列，哈希表判断是否有重复
    // 可以用字典树减少空间占用
    // 时间 O(n * 2^l)，空间 O(n*2^m)

    unordered_map<string, int> umap;

    int sz = strs.size(), cnt = 0;
    string tmp;
    function<void(int)> dfs = [&](int pos) {
        if (pos == strs[cnt].length()) {
            if (!tmp.empty()) {
                umap[tmp]++;
            }
            return;
        }

        dfs(pos + 1);
        tmp.push_back(strs[cnt][pos]);
        dfs(pos + 1);
        tmp.pop_back();
    };

    for (; cnt < sz; cnt++) {
        dfs(0);
    }

    int res = 0;
    for (auto &item : umap) {
        if (item.second == 1 && item.first.length() > res) {
            res = item.first.length();
        }
    }
    return res == 0 ? -1 : res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << findLUSlength({"aba", "cdc", "eae"}) << endl;
    // -1
    cout << findLUSlength({"aaa", "aaa", "aa"}) << endl;
    cout << findLUSlength({"aaaaaaaaaa", "bbbbbbbbbb", "cccccccccc",
                           "dddddddddd", "hggggggggg", "ihhhhhhhhh",
                           "jiiiiiiiii", "kjjjjjjjjj"})
         << endl;
    ;

    return 0;
}
