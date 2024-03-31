#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {

    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    if (len3 != len1 + len2) {
        return false;
    }

    unordered_map<int, bool> umap;
    function<bool(int, int, int, int)> dfs = [&](int which, int pos1, int pos2,
                                                 int pos3) {
        // cout << s1 << endl;
        // cout << s2 << endl;
        // cout << s3 << endl;
        // cout << which << ": " << pos1 << " " << len1 << ", " << pos2 << " "
        //      << len2 << ", " << pos3 << " " << len3 << endl;
        if (pos1 == len1 && pos2 == len2 && pos3 == len3) {
            return true;
        }
        int t = pos1 * 1000000 + pos2 * 1000 + pos3;
        if (which == 1) {
            t += 1000000000;
        }
        if (umap.find(t) != umap.end()) {
            return umap[t];
        }

        bool next = false;
        if (which == 0) {
            if (pos1 == len1 || pos3 == len3 || s1[pos1] != s3[pos3]) {
            } else {

                while (pos1 < len1 && pos3 < len3 && s1[pos1] == s3[pos3]) {
                    next = next || dfs(1, pos1 + 1, pos2, pos3 + 1);
                    if (next) {
                        break;
                    }
                    pos1++;
                    pos3++;
                }
            }
        } else {
            if (pos2 == len2 || pos3 == len3 || s2[pos2] != s3[pos3]) {
            } else {

                while (pos2 < len2 && pos3 < len3 && s2[pos2] == s3[pos3]) {
                    next = next || dfs(0, pos1, pos2 + 1, pos3 + 1);
                    if (next) {
                        break;
                    }
                    pos2++;
                    pos3++;
                }
            }
        }
        umap[t] = next;
        return next;
    };

    return dfs(0, 0, 0, 0) || dfs(1, 0, 0, 0);
}

int main(void) {
    printBool(isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    printBool(isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    printBool(isInterleave("", "", ""));
    printBool(isInterleave("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc", "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc", "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"));

    return 0;
}
