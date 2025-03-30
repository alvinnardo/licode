#include "../template/head.h"
#include <bits/stdc++.h>

int mirrorReflection(int p, int q) {
    // 题解：数学
    // 时间 O(logp)，空间 O(1)

    // 令 k 为走过的步数
    // 到顶点时，kq 是 p 的倍数
    // 如果是奇数倍，则在上面的顶点处；如果是偶数倍，则在下面的顶点
    // 根据 k 的奇偶来判断是哪个上顶点

    int m = __gcd(p, q); // 最大公约数
    int t = (p / m) * (q / m) * m;

    if (!((t / p) & 1)) {
        return 0;
    }

    return ((t / q) & 1) ? 1 : 2;
}

int mirrorReflection1(int p, int q) {
    // 思路：模拟
    // 时间 O(p)，空间 O(1)
    bool up = true, right = true; // 下一次应该怎么走
    int x = 0, y = 0;

    auto check = [&]() {
        return (x == p && y == 0) || (x == 0 && y == p) || (x == p && y == p);
    };

    while (!check()) {
        if (up) {
            if (y + q > p) {
                up = false;
                y = (p << 1) - q - y; //  p - (q - (p - y));
            } else {
                y += q;
            }
        } else {
            if (y - q < 0) {
                up = true;
                y = q - y;
            } else {
                y -= q;
            }
        }

        x = right ? p : 0;
        right = !right;
    }

    if (x == p && y == 0) {
        return 0;
    } else if (x == 0 && y == p) {
        return 2;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    // 2
    cout << mirrorReflection(2, 1) << endl;
    // 1
    cout << mirrorReflection(3, 1) << endl;

    return 0;
}
