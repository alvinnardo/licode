#include "../template/head.h"
#include <bits/stdc++.h>

string maskPII(string s) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    string tmp;
    int email = -1;
    unordered_set<char> uset{'(', ')', '-', '+', ' '}; // 审题马虎，忘记空格
    for (int i = 0; i < s.length(); i++) {
        if (!uset.count(s[i])) {
            if (s[i] == '@') {
                email = tmp.size();
            }

            if (s[i] >= 'A' && s[i] <= 'Z') {
                tmp += (char)(s[i] - 'A' + 'a');
            } else {
                tmp += s[i];
            }
        }
    }

    string res;
    if (email > 0) {
        return string() + tmp[0] + "*****" + tmp.substr(email - 1);
    }

    if (tmp.length() == 10) {
        return "***-***-" + tmp.substr(tmp.length() - 4);
    } else if (tmp.length() == 11) {
        return "+*-***-***-" + tmp.substr(tmp.length() - 4);
    } else if (tmp.length() == 12) {
        return "+**-***-***-" + tmp.substr(tmp.length() - 4);
    }

    return "+***-***-***-" + tmp.substr(tmp.length() - 4);
}

int main(int argc, char *argv[]) {
    // "l*****e@leetcode.com"
    cout << maskPII("LeetCode@LeetCode.com") << endl;
    // "a*****b@qq.com"
    cout << maskPII("AB@qq.com") << endl;
    // "***-***-7890"
    cout << maskPII("1(234)567-890") << endl;

    return 0;
}
