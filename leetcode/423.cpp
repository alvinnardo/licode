#include "../template/head.h"
#include <bits/stdc++.h>

string originalDigits(string s) {
    // 思路：找到标志位，就能确定该数字是否出现
    // 依次判断标志位数字出现的顺序即可

    // 判断顺序表
    // 时间 O(n), 空间 O(26 + n)
    vector<vector<string>> vec{{"z", "zero", "0"},  {"g", "eight", "8"},
                               {"u", "four", "4"},  {"w", "two", "2"},
                               {"x", "six", "6"},   {"f", "five", "5"},
                               {"s", "seven", "7"}, {"r", "three", "3"},
                               {"o", "one", "1"},   {"i", "nine", "9"}};

    int alpha[26]{};
    for (auto c : s) {
        alpha[c - 'a']++;
    }

    int nums[10]{};
    int idx = 0;
    while (idx < vec.size()) {
        if (alpha[vec[idx][0][0] - 'a'] > 0) {
            auto &str = vec[idx][1];
            nums[vec[idx][2][0] - '0']++;
            for (auto c : str) {
                alpha[c - 'a']--;
            }
        } else {
            idx++;
        }
    }

    // 生成结果
    string res;
    for (int i = 0; i < 10; i++) {
        while (nums[i] > 0) {
            res += i + '0';
            nums[i]--;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 012
    cout << originalDigits("owoztneoer") << endl;
    // 45
    cout << originalDigits("fviefuro") << endl;

    return 0;
}
