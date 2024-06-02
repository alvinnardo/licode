#include "../template/head.h"
#include <bits/stdc++.h>

int leastInterval(vector<char> tasks, int n) {

    // 思路：哈希表 + 贪心
    // 先把多的选了
    // 时间 O(26 * n), 空间 O(26)

    // atime 用于记录时刻
    vector<int> alpha(26), atime(26, -1);
    for (char c : tasks) {
        alpha[c - 'A']++;
    }

    int time = 0;
    while (true) {
        // 先选等的少的，再选个数多的
        int wait = INT_MAX, maxv = INT_MIN;
        int choose = -1;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] != 0) {      // 可以选
                if (atime[i] == -1) { // 不用等
                    if (wait == 0) {
                        if (alpha[i] > maxv) {
                            choose = i;
                            maxv = alpha[i];
                        }
                    } else {
                        wait = 0;
                        choose = i;
                        maxv = alpha[i];
                    }
                } else {
                    // 判断等待时间
                    int t = time > atime[i] + n ? 0 : atime[i] + n - time + 1;
                    if (t < wait) {
                        wait = t;
                        maxv = alpha[i];
                        choose = i;
                    } else if (t == wait) {
                        if (alpha[i] > maxv) {
                            maxv = alpha[i];
                            choose = i;
                        }
                    }
                }
            }
        }
        if (wait == INT_MAX) {
            break;
        }

        time += wait;
        atime[choose] = time;
        alpha[choose]--;

        time++;
    }

    return time;
}

int main(int argc, char *argv[]) {
    // 8
    cout << leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2) << endl;
    // 6
    cout << leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 0) << endl;
    // 16
    cout << leastInterval(
                {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 2)
         << endl;

    return 0;
}
