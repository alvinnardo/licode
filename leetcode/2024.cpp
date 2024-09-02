#include "../template/head.h"
#include <bits/stdc++.h>

int maxConsecutiveAnswers(string answerKey, int k) {
    // 思路：双指针
    // 时间 O(n)，空间 O(1)
    int sz = answerKey.length();

    auto getLen = [&](char ch, int k) -> int {
        int i = 0, j = 0; // 左开右闭
        int maxv = INT_MIN;

        while (i < sz) {
            // 尽量用光
            while (i < sz && (answerKey[i] == ch || k > 0)) {
                if (answerKey[i] == ch) {
                    maxv = max(maxv, i - j + 1);
                } else if (k > 0) {
                    k--;
                    maxv = max(maxv, i - j + 1);
                }
                i++;
            }

            // 恢复一个，如果是 0，则相当于借一个
            while (j < sz && k == 0) {
                if (answerKey[j++] != ch) {
                    k++;
                }
            }
        }

        return maxv;
    };

    // cout << answerKey << " " << k << " => F: " << getLen('F', k)
    //      << ", T: " << getLen('T', k) << endl;
    return max(getLen('F', k), getLen('T', k));
}

int main(int argc, char *argv[]) {
    // 4
    cout << maxConsecutiveAnswers("TTFF", 2) << endl;
    // 3
    cout << maxConsecutiveAnswers("TFFT", 1) << endl;
    // 5
    cout << maxConsecutiveAnswers("TTFTTFTT", 1) << endl;
    // 4
    cout << maxConsecutiveAnswers("TTTT", 0) << endl;
    // 6
    cout << maxConsecutiveAnswers("FFFFTTTTTT", 1) << endl;
    cout << maxConsecutiveAnswers("F", 0) << endl;
    cout << maxConsecutiveAnswers("F", 1) << endl;

    return 0;
}
