#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    // 1. 正负号
    // 2. 非小数
    // 3. 小数
    if (numerator == 0) {
        return "0";
    }
    if (denominator == 1) {
        return to_string(numerator);
    }

    // 都转成正的
    bool opt = true;
    int64_t num = numerator;
    int64_t den = denominator;
    if (numerator < 0 && denominator > 0) {
        num = -numerator;
        opt = false;
    } else if (numerator > 0 && denominator < 0) {
        den = -denominator;
        opt = false;
    }

    string res = to_string(num / den);
    int64_t mod = num % den;
    int64_t div = 0;
    if (mod == 0) {
        return opt ? res : "-" + res;
    }

    // 考虑如何获取到循环的位置
    // 用来判断是否存在相同的余数, 如果有那么就是循环
    unordered_map<int64_t, int> umap; // 记录余数和位置的关系
    vector<pair<int64_t, int64_t>> vec;   // 记录商和余数
    int cir_pos = -1;
    while (!(!vec.empty() &&
             vec.back().second == 0)) { // 最后一个余数是 0, 保证有商
        if (umap.find(mod) != umap.end()) { // 有循环
            cir_pos = umap[mod];
            vec.emplace_back(div, mod);
            break;
        }

        vec.emplace_back(div, mod);
        umap[mod] = vec.size() - 1;

        int64_t new_num = mod * 10;
        div = new_num / den;
        mod = new_num % den;
    }

    res += '.';
    for (int i = 1; i < vec.size(); i++) {
        if (i - 1 == cir_pos) {
            res += '(';
        }
        res += (char)(vec[i].first + '0');
    }

    if (cir_pos != -1) {
        res += ')';
    }

    return opt ? res : "-" + res;
}

int main(void) {
    // cout << fractionToDecimal(1, 2) << endl;
    // cout << fractionToDecimal(2, 1) << endl;
    // cout << fractionToDecimal(-2, 1) << endl;
    // cout << fractionToDecimal(4, 333) << endl;
    // cout << fractionToDecimal(-1, 333) << endl;
    // cout << fractionToDecimal(-1, -333) << endl;
    // cout << fractionToDecimal(7, -333) << endl;
    // cout << fractionToDecimal(-7, -215) << endl;
    cout << fractionToDecimal(-1, INT_MIN) << endl;
    cout << fractionToDecimal(1, INT_MAX) << endl;
    // cout << fractionToDecimal(INT_MAX, INT_MIN) << endl;
    // cout << fractionToDecimal(INT_MIN, INT_MIN) << endl;
    // cout << fractionToDecimal(INT_MAX, INT_MAX) << endl;
    // cout << fractionToDecimal(0, INT_MAX) << endl;
    // cout << fractionToDecimal(INT_MIN, 1) << endl;

    // cout << fractionToDecimal(INT_MIN, INT_MAX) << endl; // not valid

    return 0;
}
