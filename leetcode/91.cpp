#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s) {

    unordered_map<int, int> umap;
    function<int(int)> dfs = [&](int pos) {
        if (pos == s.length()) {
            return 1;
        }
        if (umap.find(pos) != umap.end()) {
            return umap[pos];
        }

        int t = 0;
        if (s[pos] >= '1' && s[pos] <= '9') {
            t += dfs(pos + 1);
        }

        if (s[pos] == '1' && pos + 1 < s.length()) {
            t += dfs(pos + 2);
        } else if (s[pos] == '2' && pos + 1 < s.length() && s[pos + 1] <= '6') {
            t += dfs(pos + 2);
        }
        umap[pos] = t;
        return t;
    };

    return dfs(0);
}

int main(void) {
    cout << numDecodings("11106") << endl;
    cout << numDecodings("226") << endl;
    cout << numDecodings("1111111111111111111111111111111111111111") << endl;

    return 0;
}
