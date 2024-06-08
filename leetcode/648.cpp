#include "../template/head.h"
#include <bits/stdc++.h>

string replaceWords(vector<string> dictionary, string sentence) {
    // 思路：哈希表
    // 时间: O(nk)，空间 O(n)
    unordered_set<string> uset;
    vector<unordered_set<int>> vec(26);
    for (auto &word : dictionary) {
        uset.insert(word);
        vec[word[0] - 'a'].insert(word.length());
    }

    int len = sentence.length();
    string tmp, res;
    bool skip = false;
    for (int i = 0; i <= len; i++) {
        if (i == len) {
            res += tmp;
            break;
        } else if (sentence[i] == ' ') {
            skip = false;
            res += tmp;
            res += ' ';
            tmp.clear();
            continue;
        }

        if (skip) {
            continue;
        }

        tmp += sentence[i];
        if (vec[tmp[0] - 'a'].count(tmp.length()) && uset.count(tmp)) {
            skip = true;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "the cat was rat by the bat"
    cout << replaceWords({"cat", "bat", "rat"},
                         "the cattle was rattled by the battery")
         << endl;
    // "a a b c"
    cout << replaceWords({"a", "b", "c"}, "aadsfasf absbs bbab cadsfafs")
         << endl;

    return 0;
}
