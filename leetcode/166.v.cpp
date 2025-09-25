#include "../template/head.h"
#include <bits/stdc++.h>

// 本次属于再次遇到，距离上一次已经大约有 1 年半 的时间
// 但这一次找循环点的部分没有绕过弯来
// 查看上一次的提交，发现之前确实写的不错
// 算法就是这样吧，有时候脑子好就能做出来，有时候堵住了就做不出来
string fractionToDecimal(int numerator, int denominator) {
    // 思路：模拟 + 哈希表
    // 时间 O(k)，空间 O(k)

    // 本题还有一个坑，就是最小负数时，转为正数会溢出，所以需要扩充位数
    // 最小负数除以 -1 是正数，会溢出，所以最开始就要转 ll
    using ll = long long;
    ll num = numerator, den = denominator;
    if (num % den == 0) { // numerator == 0 也在这里判断
        return std::to_string(num / den);
    }

    string res;
    // 判断符号
    if (num < 0 && den > 0 || num > 0 && den < 0) {
        res += "-";
        num = std::abs(num);
        den = std::abs(den);
    }

    res += std::to_string(num / den);
    num %= den;
    res += ".";
    int div{};

    // 循环点的位置是出现相同的余数时
    // 用哈希表记录位置
    unordered_map<int, int> umap;
    umap[num] = res.size(); // 第 1 个余数
    while (true) {          // 模拟除法
        num *= 10;

        div = num / den;
        num %= den;
        res += ('0' + div);
        if (num == 0) { // 能整除
            break;
        }

        if (umap.count(num) == 0) {
            umap[num] = res.size();
        } else { // insert 是在前面加，在循环点的前面加 '('
            res.insert(res.begin() + umap[num], '(');
            res.push_back(')');
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // // "0.5"
    cout << fractionToDecimal(1, 2) << endl;
    // "2"
    cout << fractionToDecimal(2, 1) << endl;
    // "0.(012)"
    cout << fractionToDecimal(4, 333) << endl;
    // "0.(0009)"
    cout << fractionToDecimal(1, 1111) << endl;
    cout << fractionToDecimal(1, 214748364) << endl;

    return 0;
}
