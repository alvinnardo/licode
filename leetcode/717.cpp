#include <bits/stdc++.h>
using namespace std;

bool isOneBitCharacter(vector<int> &&bits) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int sz = bits.size();
    for (int i = 0; i < sz; i++) {
        if (i == sz - 1) {
            return true;
        } else if (bits[i] == 1) {
            i++;
        }
    }

    return false;
}

int main(void) {
    // true
    cout << isOneBitCharacter({1, 0, 0}) << endl;
    // false
    cout << isOneBitCharacter({1, 1, 1, 0}) << endl;

    return 0;
}
