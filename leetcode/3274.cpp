#include "../template/head.h"
#include <bits/stdc++.h>

bool checkTwoChessboards(string coordinate1, string coordinate2) {
    // 思路：模拟
    // 黑：横是偶，竖是奇；横是奇，竖是偶
    // 时间 O(1)，空间 O(1)

    auto getColor = [](const std::string &pos) -> bool {
        int a = pos[0] - 'a', b = pos[1] - '1';

        return (a + b) & 1;
    };

    return getColor(coordinate1) == getColor(coordinate2);
}

int main(int argc, char *argv[]) {
    // 1
    cout << checkTwoChessboards("a1", "c3") << endl;
    // 0
    cout << checkTwoChessboards("a1", "h3") << endl;

    return 0;
}
