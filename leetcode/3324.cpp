#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> stringSequence(string target) {
    // 思路：模拟
    // 时间 O(nk)，空间 O(n)，k 是每个字符平均修改次数
    vector<string> res;
    string tmp;
    while (tmp.length() < target.length()) {
        tmp += "a";
        res.emplace_back(tmp);
        while (tmp.back() != target[tmp.length() - 1]) {
            tmp.back() += 1;
            res.emplace_back(tmp);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {"a","aa","ab","aba","abb","abc"}
    printVector(stringSequence("abc"));
    // {"a","b","c","d","e","f","g","h","ha","hb","hc","hd","he"}
    printVector(stringSequence("he"));

    return 0;
}
