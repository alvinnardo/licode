#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> decrypt(vector<int> code, int k) {

    // 思路：滑动窗口
    int sz = code.size();
    vector<int> res(sz);
    if (k == 0) {
        for (int i = 0; i < sz; i++) {
            code[i] = 0;
        }
        return code;
    } else if (k > 0) {
        int l = 1, r = k;
        int tot = accumulate(code.begin() + l, code.begin() + r + 1, 0);
        for (int i = 0; i < sz; i++) {
            res[i] = tot;
            tot -= code[l];
            l = (l + 1) % sz;
            r = (r + 1) % sz;
            tot += code[r];
        }
    } else {
        int l = sz - 1 + k, r = sz - 2;
        int tot = accumulate(code.begin() + l, code.begin() + r + 1, 0);
        for (int i = sz - 1; i >= 0; i--) {
            res[i] = tot;
            tot -= code[r];
            l = (sz + l - 1) % sz;
            r = (sz + r - 1) % sz;
            tot += code[l];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // [12,10,16,13]
    printVector(decrypt({5, 7, 1, 4}, 3));
    // [5]
    printVector(decrypt({5}, 0));
    // {12,5,6,13}
    printVector(decrypt({2, 4, 9, 3}, -2));
    // {0,0,0,0}
    printVector(decrypt({5, 7, 1, 4}, 0));

    return 0;
}
