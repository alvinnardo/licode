#include "../template/head.h"
#include <bits/stdc++.h>

int minAnagramLength(string s) {
    // 思路：哈希表 + 枚举
    // 1e5 内因子个数最多128 个，再加上减枝时间不会太长
    // 注意题目，需要字符串而不是子序列，所以固定一个子字符串，
    // 其余的子字符串每个字母出现个数要和该子字符串相同，所以需要平分原字符串
    // 时间 O(mn)，空间 O(k)，m 是平均因子个数，k 是出现的字母个数

    // 获取字母出现个数
    unordered_set<char> uset(s.begin(), s.end());
    int len = s.length();

    // 获取所有因数
    vector<int> div;
    for (int i = 1; i <= len; i++) {
        if (len % i == 0 && i >= uset.size()) {
            div.emplace_back(i);
        }
    }

    // 对每个因数进行分隔
    for (int i : div) {
        unordered_map<char, int> head, every;
        int bng = 0;
        bool find = true;
        while (bng < len) {
            every.clear();
            for (int j = bng; j < bng + i; j++) {
                if (bng == 0) {
                    head[s[j]]++;
                } else {
                    every[s[j]]++;
                }
            }

            // 第一块和总字符串比较字母个数
            // 后面块和第一块比较字母个数和每个字母频数，需要完全相同
            if (bng == 0 && head.size() != uset.size() ||
                bng != 0 && head != every) {
                find = false;
                break;
            }
            bng += i;
        }

        if (find) {
            return i;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minAnagramLength("abba") << endl;
    // 4
    cout << minAnagramLength("cdef") << endl;
    // 5
    cout << minAnagramLength("ccdef") << endl;
    // 9
    cout << minAnagramLength("aaabbbccc") << endl;
    // 6
    cout << minAnagramLength("aabbba") << endl;

    return 0;
}
