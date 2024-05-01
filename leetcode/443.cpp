#include "../template/head.h"
#include <bits/stdc++.h>

int compress(vector<char> chars) {
    // 思路：模拟，一个变量保存有效长度, 一个变量保存当前字符，一个变量保存个数
    // 可以得出，压缩后的字符数组长度一定是小于等于原长度的
    // 时间 O(n)，空间 O(1)
    char c = chars[0];
    int vec_len = 0, len = 1, sz = chars.size();
    auto handle = [&]() {
        chars[vec_len++] = c;
        if (len > 1 && len < 10) {
            chars[vec_len++] = '0' + len;
        } else if (len >= 10 && len < 100) {
            chars[vec_len++] = '0' + len / 10;
            chars[vec_len++] = '0' + len % 10;
        } else if (len >= 100 && len < 1000) {
            chars[vec_len++] = '0' + len / 100;
            chars[vec_len++] = '0' + len % 100 / 10;
            chars[vec_len++] = '0' + len % 10;
        } else if (len >= 1000) {
            chars[vec_len++] = '0' + len / 1000;
            chars[vec_len++] = '0' + len % 1000 / 100;
            chars[vec_len++] = '0' + len % 100 / 10;
            chars[vec_len++] = '0' + len % 10;
        }
    };

    for (int i = 1; i <= sz; i++) {
        if (i == sz) {
            handle();
        } else if (chars[i] != chars[i - 1]) {
            handle();
            c = chars[i];
            len = 1;
        } else {
            len++;
        }
    }

    while (chars.size() > vec_len) {
        chars.pop_back();
    }

    printVector(chars);
    return vec_len;
}

int main(int argc, char *argv[]) {
    // 6
    cout << compress({'a', 'a', 'b', 'b', 'c', 'c', 'c'}) << endl;
    // 1
    cout << compress({'a'}) << endl;
    // 4
    cout << compress({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                      'b', 'b'})
         << endl;

    return 0;
}
