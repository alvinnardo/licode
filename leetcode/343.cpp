#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int integerBreak(int n) {
    // 题解的数学方法是将分成的块的大小设置为未知数
    // 则 y = x^(n/x), 可以求得取得极大值时为 x = e
    // 由于 x 为整数，则比较 f(2) 和 f(3)，带入可得 f(3) > f(2)
    // 所以尽量把块的大小设置为 3

    if (n <= 3) {
        return n - 1;
    }

    // 对余数进行判断
    // 如果余数为 0，则都是 3;
    // 如果余数为 1，则有两个 2；
    // 如果余数为 2，则有一个 2
    if (n % 3 == 0) {
        return pow(3, n / 3);
    } else if (n % 3 == 1) {
        return pow(3, n / 3 - 1) * 4;
    }
    return pow(3, n / 3) * 2;
}

int integerBreak_my(int n) {
    // 令 y = (n/x)^x，x 是分的块数
    // 当 x > 0 时，可以求得 x = n/e 时
    // 取得极大值，由于 x 只能是整数，所以要取整

    int t = max(2, (int)(n / 2.7));
    int t1 = max(2, t + 1), t2 = max(2, t - 1);
    int res = n / t, res1 = n / t1, res2 = n / t2;
    int red = n % t, red1 = n % t1, red2 = n % t2;
    int ans = 1, ans1 = 1, ans2 = 1;
    for (int i = 0; i < t; i++) {
        ans *= res + (red-- > 0);
    }
    for (int i = 0; i < t1; i++) {
        ans1 *= res1 + (red1-- > 0);
    }
    for (int i = 0; i < t2; i++) {
        ans2 *= res2 + (red2-- > 0);
    }

    return max(max(ans, ans1), ans2);
}

int main(void) {
    integerBreak(30);
    for (int i = 2; i <= 58; i++) {
        cout << i << ": " << integerBreak(i) << endl;
    }
    return 0;
}
