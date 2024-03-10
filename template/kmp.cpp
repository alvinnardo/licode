#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// 1. 前缀 和 后缀
// 2. 最大 前缀等于后缀
// 示例: aabaaf
// a  没有前缀，没有后缀 => 0
// aa 前缀 a，后缀 a => 1
// aab 无相等前后缀 => 0
// aaba 前缀 a，后缀 a => 1
// aabaa 前缀 aa, 后缀 aa => 2
// aabaaf 无相等前后缀 => 0
// 3. next 数组三种表示
// [0,1,0,1,2,0] 原始
// [-1,0,-1,0,1,-1] 整体减一
// [-1,0,1,0,1,2] 整体右移

void getNext(const std::string &match, vector<int> &next) {
    // a a b a a f
    int j = 0; // j 是前缀，i 是后缀
    for (int i = 1; i < match.size(); i++) {
        while (j > 0 && match[j] != match[i]) {
            j = next[j - 1];
        }

        // 上面其实已经回退到相等的位置了
        // 如果还不相等，其实已经是第 0 位了
        if (match[i] == match[j]) {
            j++; // 先变长度
            next[i] = j;
        }
    }
    printVector(next);
}

bool stringMatch(const std::string &ori, const std::string &match) {

    vector<int> next(match.length());
    getNext(match, next);

    int i = 0, j = 0;
    while (i < ori.length() && j < match.length()) {
        if (ori[i] == match[j]) {
            i++;
            j++;
        } else {
            if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }

    if (j == match.size()) {
        return true;
    }

    return false;
}

int main(void) {

    printBool(stringMatch("aabaabaaf", "aabaaf"));
    printBool(stringMatch("aabaaaaafaababaacaafaaab", "aabaaf"));
    printBool(stringMatch("aabaaaaafaabafaabaafaaab", "aabaaf"));

    return 0;
}
