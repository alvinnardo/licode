#include "../template/head.h"
#include <bits/stdc++.h>

string intToRoman(int num) {
    // 思路：模拟
    // 时间 O(klogk)，空间 O(1)
    vector<pair<int, string>> vec{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};

    // 每次找小于等于的数
    int sz = vec.size();
    string res;
    while (num) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].first <= num) {
                res += vec[i].second;
                num -= vec[i].first;
                break;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "MMMDCCXLIX"
    cout << intToRoman(3749) << endl;
    // "LVIII"
    cout << intToRoman(58) << endl;
    // "MCMXCIV"
    cout << intToRoman(1994) << endl;

    return 0;
}
