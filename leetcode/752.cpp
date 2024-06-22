#include "../template/head.h"
#include <bits/stdc++.h>

int openLock(vector<string> deadends, string target) {
    // 思路：层序遍历
    // 时间 O(k)，空间 O(k)，k 是状态个数

    unordered_set uset(deadends.begin(), deadends.end());

    queue<string> qu;
    qu.emplace("0000");

    unordered_set<string> visited;
    int level = 0;
    while (!qu.empty()) {

        int cnt = qu.size();
        while (cnt--) {
            string t = qu.front();
            qu.pop();
            if (t == target) {
                return level;
            }

            if (uset.count(t) || visited.count(t)) {
                continue;
            }
            visited.insert(t);
            for (int i = 0; i < 4; i++) {
                char c = t[i];
                t[i] = t[i] == '9' ? '0' : t[i] + 1;
                qu.push(t);
                t[i] = c;

                t[i] = t[i] == '0' ? '9' : t[i] - 1;
                qu.push(t);
                t[i] = c;
            }
        }
        level++;
    }

    return -1;
}
int main(int argc, char *argv[]) {
    // 6
    cout << openLock({"0201", "0101", "0102", "1212", "2002"}, "0202") << endl;
    // 4
    cout << openLock({"8888", "0009"}, "0008") << endl;
    // 1
    cout << openLock({"8888", "0010"}, "0009") << endl;
    // -1
    cout << openLock({"8887", "8889", "8878", "8898", "8788", "8988", "7888",
                      "9888"},
                     "8888")
         << endl;

    return 0;
}
