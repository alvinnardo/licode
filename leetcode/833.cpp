#include "../template/head.h"
#include <bits/stdc++.h>

string findReplaceString(string s, vector<int> indices, vector<string> sources,
                         vector<string> targets) {
    // 思路：排序 + 模拟
    // 顺序遍历 s，如果在 indices 中，需要判断是否能匹配上
    // 需要排序一下索引位置，且需要方便查找，所以使用了红黑树
    // 时间 O(n + km + klog(k))，空间 O(k)
    // 结果字符串不涉及中间运算过程，不算入空间中
    // n 是 s 长度，k 是索引数组个数，m 是 sources 中字符串平均长度

    map<int, vector<int>> mm;
    int k = indices.size();
    for (int i = 0; i < k; i++) {
        mm[indices[i]].emplace_back(i);
    }

    string res;
    for (int j = 0; j < s.length(); j++) {
        if (mm.count(j)) {
            auto &pos_vec = mm[j];
            int matched_pos = -1;
            for (int pos : pos_vec) {

                // 剩余字符不够，不用试了
                if (s.length() - j < sources[pos].length()) {
                    continue;
                }

                bool matched = true;
                for (int k = 0; k < sources[pos].length(); k++) {
                    if (sources[pos][k] != s[j + k]) {
                        matched = false;
                        break;
                    }
                }

                if (matched) {
                    matched_pos = pos;
                    break;
                }
            }

            if (matched_pos >= 0) {
                j += sources[matched_pos].length() - 1;
                res += targets[matched_pos];
            } else {
                res.push_back(s[j]);
            }
        } else {
            res.push_back(s[j]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "eeebffff"
    cout << findReplaceString("abcd", {0, 2}, {"a", "cd"}, {"eee", "ffff"})
         << endl;
    // "eeecd"
    cout << findReplaceString("abcd", {0, 2}, {"ab", "ec"}, {"eee", "ffff"})
         << endl;
    // "abfe"
    cout << findReplaceString("abcde", {2, 2, 3}, {"cde", "cdef", "dk"},
                              {"fe", "f", "xyz"})
         << endl;

    return 0;
}
