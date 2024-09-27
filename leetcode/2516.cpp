#include "../template/head.h"
#include <bits/stdc++.h>

int takeCharacters(string s, int k) {
    // 题解：双指针
    // 转化为求中间最大的窗口，窗口越大越好
    // 条件满足则扩大窗口，否则缩小窗口
    // 时间 O(n)，空间 O(1)

    int len = s.length();
    int a_cnt = 0, b_cnt = 0, c_cnt = 0;
    for (int i = 0; i < len; i++) {
        a_cnt += s[i] == 'a';
        b_cnt += s[i] == 'b';
        c_cnt += s[i] == 'c';
    }

    if (a_cnt < k || b_cnt < k || c_cnt < k) {
        return -1;
    }

    int left = 0, res = -1; // 左开右闭
    for (int i = 0; i < len; i++) {
        a_cnt -= s[i] == 'a';
        b_cnt -= s[i] == 'b';
        c_cnt -= s[i] == 'c';
        // 第三个用例，窗口长度可以为 0，注意这里的等号
        while (left <= i && (a_cnt < k || b_cnt < k || c_cnt < k)) {
            a_cnt += s[left] == 'a';
            b_cnt += s[left] == 'b';
            c_cnt += s[left] == 'c';
            left++;
        }

        if (a_cnt >= k && b_cnt >= k && c_cnt >= k) {
            res = max(res, i - left + 1);
        }
    }

    return len - res;
}

int takeCharacters_my(string s, int k) {
    // 思路：二分 + 滑动窗口
    // 滑动中间的窗口，窗口越大越好
    // 时间 O(nlogn)，空间 O(1)
    int len = s.length();
    int a_cnt = 0, b_cnt = 0, c_cnt = 0;
    for (int i = 0; i < len; i++) {
        a_cnt += s[i] == 'a';
        b_cnt += s[i] == 'b';
        c_cnt += s[i] == 'c';
    }

    if (a_cnt < k || b_cnt < k || c_cnt < k) {
        return -1;
    }

    auto satisfy = [=](int a_cnt, int b_cnt, int c_cnt, int sz) -> bool {
        // 所有的减去窗口内后是否满足条件
        int i = 0; // 左开右闭
        for (int j = 0; j < len; j++) {
            a_cnt -= s[j] == 'a';
            b_cnt -= s[j] == 'b';
            c_cnt -= s[j] == 'c';

            if (j - i + 1 > sz) {
                a_cnt += s[i] == 'a';
                b_cnt += s[i] == 'b';
                c_cnt += s[i] == 'c';
                i++;
            }

            if (j - i + 1 == sz && a_cnt >= k && b_cnt >= k && c_cnt >= k) {
                return true;
            }
        }

        return false;
    };

    int left = 0, right = len; // 窗口大小在 0 到 len 之间
    int res = -1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (satisfy(a_cnt, b_cnt, c_cnt, mid)) {
            res = len - mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 8
    cout << takeCharacters("aabaaaacaabc", 2) << endl;
    // -1
    cout << takeCharacters("a", 1) << endl;
    // 3
    cout << takeCharacters("abc", 1) << endl;

    return 0;
}
