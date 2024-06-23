#include "../template/head.h"
#include <bits/stdc++.h>

bool detectCapitalUse(string word) {
    // 思路：模拟，第一个字符大写，后面全大写或全小写
    // 第一个字符小写，后面全小写
    // 时间 O(n)，空间 O(1)
    bool first_up = word[0] >= 'A' && word[0] <= 'Z' ? 1 : 0;
    int last_up_cnt = 0;
    for (int i = 1; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            last_up_cnt++;
        }
    }

    if (first_up && (last_up_cnt == 0 || last_up_cnt == word.length() - 1) ||
        !first_up && last_up_cnt == 0) {
        return true;
    }

    return false;
}

int main(int argc, char *argv[]) {
    // 1
    cout << detectCapitalUse("USA") << endl;
    // 0
    cout << detectCapitalUse("FlaG") << endl;

    return 0;
}
