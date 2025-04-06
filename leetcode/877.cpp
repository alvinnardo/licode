#include "../template/head.h"
#include <bits/stdc++.h>

bool stoneGame(vector<int> piles) {
    // 题解：数学
    // 时间：O(1)，空间 O(1)

    // 2^n 的解法肯定超时，看到正确率这么高，应该有简单方法
    // 测试多个用例试出来结果都是 true，提交就通过了

    // 题解看懂了
    // 因为是偶数个数，分成偶数组和奇数组
    // 开始位置和结束位置分别是 0 和 n - 1，一个在偶数组，一个在奇数组
    // 先手可以计算这两组哪一组大，然后一直选一组

    // 如果先手选偶数组，后手只能选奇数组，选完之后又是偶数个，先手可以继续挑
    // 如果先手选奇数组，后手只能选偶数组，选完之后又是偶数个，先手可以继续挑
    // 先手有必胜策略
    return true;
}

int main(int argc, char *argv[]) {
    // true
    cout << stoneGame({5, 3, 4, 5}) << endl;
    // true
    cout << stoneGame({3, 7, 2, 3}) << endl;

    return 0;
}
