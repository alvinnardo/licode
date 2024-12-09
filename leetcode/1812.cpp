#include "../template/head.h"
#include <bits/stdc++.h>

bool squareIsWhite(string coordinates) {
    // 思路：找规律
    // 偶黑奇白
    // 时间 O(1)，空间 O(1)

    return ((int)(coordinates[0] - 'a') + (int)(coordinates[1] - '1')) & 1;
}

int main(int argc, char *argv[]) {
    // 0
    cout << squareIsWhite("a1") << endl;
    // 1
    cout << squareIsWhite("h3") << endl;
    // 0
    cout << squareIsWhite("c7") << endl;

    return 0;
}
