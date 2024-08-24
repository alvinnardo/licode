#include "../template/head.h"
#include <bits/stdc++.h>

int findPermutationDifference(string s, string t) {
    // 思路：哈希表
    // 时间: O(n + k)，空间 O(k)
    vector<int> s_vec(26), t_vec(26);

    for (int i = 0; i < s.length(); i++) {
        s_vec[s[i] - 'a'] = i;
        t_vec[t[i] - 'a'] = i;
    }

    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += abs(s_vec[i] - t_vec[i]);
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 2
    cout << findPermutationDifference("abc", "bac") << endl;
    // 12
    cout << findPermutationDifference("abcde", "edbac") << endl;

    return 0;
}
