#include "../template/head.h"
#include <bits/stdc++.h>

string complexNumberMultiply(string num1, string num2) {
    // 思路：模拟
    auto getPair = [](const string &str) -> pair<int, int> {
        bool real_neg = false, xu_neg = false;
        int real = 0, xu = 0, len = str.length();
        bool add_flag = false;
        for (int i = 0; i < len - 1; i++) {
            if (str[i] == '+') {
                add_flag = true;
                continue;
            }

            if (add_flag == false) {
                if (str[i] == '-') {
                    real_neg = true;
                } else {
                    real = real * 10 + (int)(str[i] - '0');
                }
            } else {
                if (str[i] == '-') {
                    xu_neg = true;
                } else {
                    xu = xu * 10 + (int)(str[i] - '0');
                }
            }
        }
        if (real_neg) {
            real = -real;
        }
        if (xu_neg) {
            xu = -xu;
        }
        return {real, xu};
    };

    auto getStr = [](pair<int, int> &p) {
        string res;
        if (p.first < 0) {
            res += '-';
            p.first = -p.first;
        }
        res += to_string(p.first);
        res += '+';
        if (p.second < 0) {
            res += '-';
            p.second = -p.second;
        }
        res += to_string(p.second);
        res += 'i';

        return res;
    };

    pair<int, int> p1 = getPair(num1), p2 = getPair(num2);
    pair<int, int> p3 = {p1.first * p2.first + (-1) * p1.second * p2.second,
                         p1.first * p2.second + p1.second * p2.first};

    return getStr(p3);
}

int main(int argc, char *argv[]) {
    // "0+2i"
    cout << complexNumberMultiply("1+1i", "1+1i") << endl;
    // "0+-2i"
    cout << complexNumberMultiply("1+-1i", "1+-1i") << endl;

    return 0;
}
