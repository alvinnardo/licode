#include "../template/head.h"
#include <bits/stdc++.h>

long long validSubstringCount(string word1, string word2) {
    // 思路：双指针
    // 时间 O(m + n)，空间 O(C)
    // 讨论一下复杂度
    // 该题与上一题类似，但是 word1 长度变大
    // m 是 word2 长度，n 是 word1 长度，C 是字母个数为常数 26
    // 1. 对于昨天的方法一：哈希表 + 二分，
    //    时间复杂度是 O(nClogn + m)，空间复杂度 O(nC)
    //    每次查找后需要用前缀数组的方式求得差异，且每次二分找完之后都需要对比
    // 2. 昨天我的方法是用双指针，但是每次找到后也是全部对比，
    //    时间复杂度准确是 O(nC + m)，空间复杂度 O(C)
    // 3. 今天的方法也是用双指针，但是只需要比较不同的个数，不需要全部对比，
    //    所以时间复杂度是 O(m + n)，空间复杂度 O(C)
    long long res = 0;
    vector<int> vw1(26), vw2(26);
    for (auto &c : word2) {
        vw2[c - 'a']++;
    }

    int diff = count_if(vw2.begin(), vw2.end(), [](int _) { return _ > 0; });
    int sz = word1.length();
    int j = 0;

    auto handle = [&](int pos, int d) {
        int t = vw1[pos] + d;
        if (vw1[pos] == vw2[pos] && t < vw2[pos]) {
            diff++;
        } else if (vw1[pos] < vw2[pos] && t == vw2[pos]) {
            diff--;
        }

        vw1[pos] = t;
    };

    for (int i = 0; i < sz; i++) {
        handle(word1[i] - 'a', 1);

        while (diff == 0) {
            res += sz - i;
            handle(word1[j] - 'a', -1);
            j++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << validSubstringCount("bcca", "abc") << endl;
    // 10
    cout << validSubstringCount("abcabc", "abc") << endl;
    // 0
    cout << validSubstringCount("abcabc", "aaabc") << endl;
    // 18
    cout << validSubstringCount("dcbdcdccb", "cdd") << endl;

    return 0;
}
