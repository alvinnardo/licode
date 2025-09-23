#include "../template/head.h"
#include <bits/stdc++.h>

int compareVersion(string version1, string version2) {
    // 思路：模拟
    // 时间 O(m + n)，空间 O(k)，k 是中间最长字符串长度

    int m = 0, n = 0;
    string tmpm, tmpn;
    while (m < version1.length() || n < version2.length()) {
        while (m < version1.length()) {
            if (version1[m] != '.') {
                tmpm += version1[m++];
            } else {
                m++;
                break;
            }
        }

        while (n < version2.length()) {
            if (version2[n] != '.') {
                tmpn += version2[n++];
            } else {
                n++;
                break;
            }
        }

        int a = tmpm.size() == 0 ? 0 : stoi(tmpm);
        int b = tmpn.size() == 0 ? 0 : stoi(tmpn);
        if (a < b) {
            return -1;
        } else if (a > b) {
            return 1;
        }
        tmpm.clear();
        tmpn.clear();
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // -1
    cout << compareVersion("1.2", "1.10") << endl;
    // 0
    cout << compareVersion("1.01", "1.001") << endl;
    // 0
    cout << compareVersion("1.0", "1.0.0.0") << endl;
    // 1
    cout << compareVersion("1.0.1", "1") << endl;

    return 0;
}
