#include "../template/head.h"
#include <bits/stdc++.h>

int romanToInt(string s) {
    // 题解：模拟
    // 时间 O(n)，空间 O(1)

    // 在规则中，除了特殊情况外，都是左边大于等于右边
    // 即除了特殊情况外，不会有左边小于右边的情况发生
    // 所以出现特殊情况时直接减去左边的小值即可
    unordered_map<char, int> umap{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};
    int sz = s.length(), res{};
    for (int i = 0; i < sz; i++) {
        int t = umap[s[i]];
        if (i + 1 < sz && t < umap[s[i + 1]]) {
            res -= t;
        } else {
            res += t;
        }
    }

    return res;
}

int romanToInt1(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int sz = s.length(), res{};
    for (int i = 0; i < sz; ++i) {
        if (s[i] == 'I') {
            if (i + 1 < sz) {
                if (s[i + 1] == 'V') {
                    res += 4;
                    ++i;
                } else if (s[i + 1] == 'X') {
                    res += 9;
                    ++i;
                } else {
                    res += 1;
                }
            } else {
                res += 1;
            }
        } else if (s[i] == 'V') {
            res += 5;
        } else if (s[i] == 'X') {
            if (i + 1 < sz) {
                if (s[i + 1] == 'L') {
                    res += 40;
                    ++i;
                } else if (s[i + 1] == 'C') {
                    res += 90;
                    ++i;
                } else {
                    res += 10;
                }
            } else {
                res += 10;
            }
        } else if (s[i] == 'L') {
            res += 50;
        } else if (s[i] == 'C') {
            if (i + 1 < sz) {
                if (s[i + 1] == 'D') {
                    res += 400;
                    ++i;
                } else if (s[i + 1] == 'M') {
                    res += 900;
                    ++i;
                } else {
                    res += 100;
                }
            } else {
                res += 100;
            }
        } else if (s[i] == 'D') {
            res += 500;
        } else if (s[i] == 'M') {
            res += 1000;
        } else {
            // other
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << romanToInt("III") << endl;
    // 4
    cout << romanToInt("IV") << endl;
    // 9
    cout << romanToInt("IX") << endl;
    // 58
    cout << romanToInt("LVIII") << endl;
    // 1994
    cout << romanToInt("MCMXCIV") << endl;

    return 0;
}
