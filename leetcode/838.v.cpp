#include "../template/head.h"
#include <bits/stdc++.h>

string pushDominoes(string dominoes) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    // 细节较多: 本质上是标记左位置，看右位置
    bool is_right_force = false, right_force_pos = 0;
    int j = 0;
    int sz = dominoes.length();
    for (int i = 0; i < sz; i++) {
        if (dominoes[i] == 'L') {
            if (!is_right_force) {
                while (j <= i) {
                    dominoes[j++] = 'L';
                }
            } else {
                int cnt = i - j + 1;
                bool f = cnt & 1;
                cnt >>= 1;
                for (int k = 0; k < cnt; k++) {
                    dominoes[j++] = 'R';
                }
                if (f) {
                    dominoes[j++] = '.';
                }
                for (int k = 0; k < cnt; k++) {
                    dominoes[j++] = 'L';
                }
                is_right_force = false; // 还原
            }
        } else if (dominoes[i] == 'R') {
            if (!is_right_force) {
                is_right_force = true;
                while (j < i) {
                    dominoes[j++] = '.';
                }
            } else {
                while (j < i) {
                    dominoes[j++] = 'R';
                }
            }
        }
    }

    while (j < sz) {
        dominoes[j++] = is_right_force ? 'R' : '.';
    }
    return dominoes;
}

int main(int argc, char *argv[]) {
    // "RR.L"
    cout << pushDominoes("RR.L") << endl;
    // "LL.RR.LLRRLL.."
    cout << pushDominoes(".L.R...LR..L..") << endl;

    return 0;
}
