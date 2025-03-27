#include "../template/head.h"
#include <bits/stdc++.h>

long long minimumCost(string s) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)

    // 分奇偶讨论
    // 奇数的话，两边需要和中间相同
    // 偶数的话，两边先相同，再翻一次中间
    long long res{};

    int len = s.length();
    auto handle = [&](int pos, char c, bool is_left) -> long long {
        long long tot{};
        int cnt{};
        if (is_left) {
            for (int i = pos; i >= 0; i--) {
                if (s[i] != c && !cnt || s[i] == c && cnt) { // 翻
                    tot += (i + 1);
                    cnt = (cnt + 1) % 2;
                }
            }
        } else {
            for (int i = pos; i < len; i++) {
                if (s[i] != c && !cnt || s[i] == c && cnt) {
                    tot += (len - i);
                    cnt = (cnt + 1) % 2;
                }
            }
        }

        return tot;
    };

    if (len & 1) {
        int mid_pos = (len >> 1);
        res += handle(mid_pos - 1, s[mid_pos], true);
        res += handle(mid_pos + 1, s[mid_pos], false);
    } else {
        int left_pos = (len >> 1) - 1, right_pos = (len >> 1);
        res += handle(left_pos - 1, s[left_pos], true);
        res += handle(right_pos + 1, s[right_pos], false);
        if (s[left_pos] != s[right_pos]) {
            res += (len >> 1);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minimumCost("0011") << endl;
    // 9
    cout << minimumCost("010101") << endl;

    return 0;
}
