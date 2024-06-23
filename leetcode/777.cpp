#include "../template/head.h"
#include <bits/stdc++.h>

// 题解中给出判断相对位置 + 再判断 end 和 start 的位置变化大小即可
// 比如 end 中的 L 要小于 start 中的 L
// end 中的 R 要大于 start 中的 R
bool canTransform(string start, string end) {
    // 思路：贪心，只要有一个 X 就能进行替换，
    // 并且两个串中的 R L相对位置是一样的
    // 还要判断移动位置是否合法
    // 时间 O(n)，空间 O(n)
    string tmp1, tmp2;
    bool x = false;
    vector<int> r_pos_vec;
    vector<pair<int, int>> l_vec, r_vec;
    for (int i = 0; i <= start.length(); i++) {
        if (i == start.length() || start[i] == 'L') {
            for (int pos : r_pos_vec) {
                r_vec.emplace_back(pos, i);
            }
            r_pos_vec.clear();
            tmp1 += start[i];
        } else if (start[i] == 'R') {
            r_pos_vec.push_back(i);
            tmp1 += start[i];
        }

        if (end[i] != 'X') {
            tmp2 += end[i];
        }
    }

    vector<int> l_pos_vec;
    for (int i = start.length() - 1; i >= -1; i--) {
        if (i == -1 || start[i] == 'R') {
            for (int pos : l_pos_vec) {
                l_vec.emplace_back(i + 1, pos + 1);
            }
            l_pos_vec.clear();
        } else if (start[i] == 'L') {
            l_pos_vec.push_back(i);
        }
    }

    if (tmp1 != tmp2) {
        return false;
    }

    int l_pos = l_vec.size() - 1, r_pos = 0;
    for (int i = 0; i < end.length(); i++) {
        if (end[i] == 'L') {
            if (!(l_vec[l_pos].first <= i && i < l_vec[l_pos].second)) {
                return false;
            }
            l_pos--;
        } else if (end[i] == 'R') {
            if (!(r_vec[r_pos].first <= i && i < r_vec[r_pos].second)) {
                return false;
            }
            r_pos++;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // 1
    cout << canTransform("RXXLRXRXL", "XRLXXRRLX") << endl;
    // 0
    cout << canTransform("X", "L") << endl;
    // 0
    cout << canTransform("LXXLXRLXXL", "XLLXRXLXLX") << endl;
    // 0
    cout << canTransform("XXXXXXRXXXXXXXXLXXXXXXXXXLXXXXXXXLXXXXRXXXXXXXXXXX",
                         "XXXXXXXXRXXXXXXXLXXXXXLXXXXXXXXLXXXXXXXXXXXRXXXXXX")
         << endl;
    // 0
    cout << canTransform("XRXXXLXXXR", "XXRLXXXRXX") << endl;

    return 0;
}
