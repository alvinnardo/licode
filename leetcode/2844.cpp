#include "../template/head.h"
#include <bits/stdc++.h>

int minimumOperations(string num) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)
    int sz = num.size();

    int zero_pos = -1, five_pos = -1;
    for (int i = sz - 1; i >= 0; i--) {
        if (num[i] == '0' && zero_pos == -1) {
            zero_pos = i;
        } else if (num[i] == '5' && five_pos == -1) {
            five_pos = i;
        }
    }

    if (zero_pos < 0 && five_pos < 0) {
        return sz;
    }

    int max_zero = INT_MAX, max_five = INT_MAX;
    auto getMax = [&](int &pos, int &max_val, const unordered_set<char> &uset) {
        int i = pos - 1;
        while (i >= 0) {
            if (uset.count(num[i])) {
                break;
            }
            i--;
        }

        if (i != -1) {
            max_val = sz - i - 2;
        }
    };

    if (zero_pos >= 0) { // 找 0, 5
        getMax(zero_pos, max_zero, {'0', '5'});
        if (max_zero == INT_MAX) {
            max_zero = sz - 1;
        }
    }
    if (five_pos >= 0) { // 找 2, 7
        getMax(five_pos, max_five, {'2', '7'});
        if (max_five == INT_MAX) {
            max_five = sz;
        }
    }

    return min(max_zero, max_five);
}

int main(int argc, char *argv[]) {

    // 2
    cout << minimumOperations("2245047") << endl;
    // 3
    cout << minimumOperations("2908305") << endl;
    // 1
    cout << minimumOperations("10") << endl;
    // 1
    cout << minimumOperations("55555") << endl;

    return 0;
}
