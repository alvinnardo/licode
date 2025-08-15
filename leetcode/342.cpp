#include "../template/head.h"
#include <bits/stdc++.h>

// 灵神给出了两种解法
// 解法1：先判断是 2 的幂，再 n & 0x55555555 > 0 把可能是 1 的位置提取出来
// 解法2：先判断是 2 的幂，再 n % 3 == 1，根据二项式定理得出

// *思考：判断 n 是 k 次幂的通用解法
// 评论中给出了解法：通用的直接 while 转 k 进制，只有最高位是 1
// 如果 k 是 2 的幂，则用上述方法 1
// 如果 k 是素数，则用题目给出范围计算可能的最大值 maxv，再判断 maxv % n == 0

bool isPowerOfFour(int n) {
    // 思路：位运算
    // 时间 O(1)，空间 O(1)

    // 首先是 2 的幂
    // WA 的用例是 2，开根号取整后是 1，返回正确的，是不对的
    // 所以不开根号，判断二进制的 1 右边有偶数个 0 即可
    return n > 0 && std::has_single_bit((uint)n) &&
           !(std::countr_zero((uint)n) & 1);
}

int main(int argc, char *argv[]) {
    // 1
    cout << isPowerOfFour(16) << endl;
    // 0
    cout << isPowerOfFour(5) << endl;
    // 1
    cout << isPowerOfFour(1) << endl;

    return 0;
}
