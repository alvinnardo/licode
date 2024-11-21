#include "../template/head.h"
#include <bits/stdc++.h>

int finalPositionOfSnake(int n, vector<string> commands) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int pos = 0;
    unordered_map<string, int> direct{
        {"RIGHT", 1}, {"LEFT", -1}, {"UP", -n}, {"DOWN", n}};
    for (const auto &command : commands) {
        pos += direct[command];
    }

    return pos;
}

int main(int argc, char *argv[]) {
    // 3
    cout << finalPositionOfSnake(2, {"RIGHT", "DOWN"}) << endl;
    // 1
    cout << finalPositionOfSnake(3, {"DOWN", "RIGHT", "UP"}) << endl;

    return 0;
}
