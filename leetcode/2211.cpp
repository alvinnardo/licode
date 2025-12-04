#include "../template/head.h"
#include <bits/stdc++.h>

int countCollisions(string directions) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)

    // 获取所有静止的位置，往两边遍历
    vector<int> vec;
    int res{};
    for (int i = 0; i < directions.size(); i++) {
        if (directions[i] == 'S') {
            vec.push_back(i);
        } else if (directions[i] == 'R' && i + 1 < directions.size() &&
                   directions[i + 1] == 'L') {
            vec.push_back(i);
            directions[i] = 'S';
            ++i;
            vec.push_back(i);
            directions[i] = 'S';
            res += 2;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        int pos = vec[i];
        for (int j = pos - 1; j >= 0; j--) {
            if (directions[j] == 'S') {
                break;
            } else if (directions[j] == 'R') {
                ++res;
            }
        }

        for (int j = pos + 1; j < directions.size(); j++) {
            if (directions[j] == 'S') {
                break;
            } else if (directions[j] == 'L') {
                ++res;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 5
    cout << countCollisions("RLRSLL") << endl;
    // 0
    cout << countCollisions("LLRR") << endl;

    return 0;
}
