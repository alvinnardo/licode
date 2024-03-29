#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool isValid(const std::string &num, int apos, int alen, int bpos, int blen,
             int cpos, int clen) {
    int len = num.length();

    if (cpos == len) {
        return true;
    }
    if (cpos + clen - 1 >= len) {
        return false;
    }

    auto getLLong = [&](int pos, int len) -> long long {
        long long t = 0;
        for (int i = 0; i < len; i++) {
            t = t * 10 + (num[pos + i] - '0');
        }
        return t;
    };

    if (alen > 1 && num[apos] == '0' || blen > 1 && num[bpos] == '0' ||
        clen > 1 && num[cpos] == '0') {
        return false;
    }

    auto a = getLLong(apos, alen);
    auto b = getLLong(bpos, blen);
    auto c = getLLong(cpos, clen);
    // cout << a << " " << b << " " << c << endl;
    if (a + b != c) {
        return false;
    }

    int span = max(alen, blen);
    return isValid(num, bpos, blen, cpos, clen, cpos + clen, span) ||
           isValid(num, bpos, blen, cpos, clen, cpos + clen, span + 1);
}

bool isAdditiveNumber(string num) {
    cout << num << endl;
    int len = num.length();
    if (len < 3) {
        return 0;
    }

    // 第一次的时候枚举所有三个数
    // 在循环中，第三个数的长度不能小于前两个数的最大长度
    // 不会大于前两个数的最大长度 + 1
    for (int i = 1; i <= len - 2; i++) {
        for (int j = 1; j <= len - i - 1; j++) {
            int span = max(i, j);
            if (isValid(num, 0, i, i, j, i + j, span) ||
                isValid(num, 0, i, i, j, i + j, span + 1)) {
                return true;
            }
        }
    }

    return 0;
}

int main(void) {

    printBool(isAdditiveNumber("112358"));                                // t
    printBool(isAdditiveNumber("199100199"));                             // t
    printBool(isAdditiveNumber("1242342348273498237498273489274972"));    // f
    printBool(isAdditiveNumber("1000020000300005000080000130000210000")); // t
    printBool(isAdditiveNumber("19991000999199980009999999"));            // f
    printBool(isAdditiveNumber("19991000199929994998799712995"));         // t
    printBool(isAdditiveNumber("11111111111111111111111111111111111"));   // f
    printBool(isAdditiveNumber("111122"));                                // t
    printBool(isAdditiveNumber("1203"));                                  // f
    printBool(isAdditiveNumber("10112"));                                 // t
    printBool(isAdditiveNumber("01123"));                                 // t
    printBool(isAdditiveNumber("11011"));                                 // t

    return 0;
}
