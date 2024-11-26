#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfAlternatingGroups(vector<int> colors) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int sz = colors.size();
    int id2 = 0, id3 = 0;

    int res = 0;
    for (int i = 0; i < sz; i++) {
        id2 = (i + 1) % sz;
        id3 = (i + 2) % sz;
        if (colors[i] == 0 && colors[id2] == 1 && colors[id3] == 0 ||
            colors[i] == 1 && colors[id2] == 0 && colors[id3] == 1) {
            res++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 0
    cout << numberOfAlternatingGroups({1, 1, 1}) << endl;
    // 1
    cout << numberOfAlternatingGroups({0, 0, 1}) << endl;
    // 1
    cout << numberOfAlternatingGroups({1, 0, 1}) << endl;
    // 3
    cout << numberOfAlternatingGroups({0, 1, 0, 0, 1}) << endl;

    return 0;
}
