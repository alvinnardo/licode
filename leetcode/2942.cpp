#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findWordsContaining(vector<string> words, char x) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    vector<int> res;
    int sz = words.size();
    for (int i = 0; i < sz; i++) {
        if (words[i].find(x) != std::string::npos) {
            res.push_back(i);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {0,1}
    printVector(findWordsContaining({"leet", "code"}, 'e'));
    // {0,2}
    printVector(findWordsContaining({"abc", "bcd", "aaaa", "cbc"}, 'a'));
    // {}
    printVector(findWordsContaining({"abc", "bcd", "aaaa", "cbc"}, 'z'));

    return 0;
}
