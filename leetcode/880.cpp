#include "../template/head.h"
#include <bits/stdc++.h>

string decodeAtIndex(string s, int k) {
    // 思路：二分
    // 时间 O(mlogm)，空间 O(m)，m 是 s 中数字个数
    // 模拟较为复杂的一道题

    // 依次处理每一段，如果长度大于 k 就停止
    // 二分查找长度，每次对每段长度取余
    // 直到取余后不变，就落在那一段上
    struct Ele {
        int bng = -1;
        int end = -1;
        long long tot = -1;
        long long tot_after = -1;

        Ele(int a, int b, long long c, long long d)
            : bng(a), end(b), tot(c), tot_after(d) {}
    };

    vector<Ele> vec;
    int len = s.length();
    int bng = -1, end = -1;
    long long tot = 0;
    for (int i = 0; i < len + 1; i++) {
        if (i == len) {
            if (bng > -1) {
                vec.emplace_back(bng, end, tot, tot);
            }

            continue;
        }

        char c = s[i];
        if (isdigit(c)) {
            if (bng < 0) { // 没有字符，直接数字，用前一个的范围
                auto &b = vec.back();
                vec.emplace_back(b.bng, b.end, b.tot_after, 0);
            } else {
                vec.emplace_back(bng, end, tot, 0);
            }
            bng = end = -1;

            int t = c - '0';
            vec.back().tot_after = tot * t;
            tot = vec.back().tot_after;
            if (tot > k) {
                break;
            }

        } else {
            if (bng < 0) {
                bng = i;
            }
            end = i;

            tot++;
        }
    }

    int pre = -1;
    string res = " ";
    while (true) { // 如果两次都落在一段，则就属于这段
        auto pos = lower_bound(vec.begin(), vec.end(), k,
                               [](const auto &t, long long k) {
                                   return t.tot_after < k;
                               }) -
                   vec.begin();

        auto &t = vec[pos];
        if (pre == pos) {
            res.back() = s[t.end - (int)(t.tot - k)];
            break;
        } else {
            k = (k - 1) % t.tot + 1;
            pre = pos;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "a"
    cout << decodeAtIndex("abc", 1) << endl;
    // "o"
    cout << decodeAtIndex("leet2code3", 10) << endl;
    // "h"
    cout << decodeAtIndex("ha22", 5) << endl;
    // "a"
    cout << decodeAtIndex("a2345678999999999999999", 1) << endl;

    return 0;
}
