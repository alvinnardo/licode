#include "../template/head.h"
#include <bits/stdc++.h>

int minSwaps(string s) {
    // 思路: 贪心
    // 时间 O(n)，空间 O(1)
    // 本质上是依次交换左边不成立的 ']'，和右边不成立的 '['

    // 没太明白原理，但是蒙对了 <_< (看灵神的思路，讲得好)
    // 不用真的交换，如果后面遇到了本该交换到右边的左括号
    // 直接加即可，不会导致结果变大，只是 left 增大，其实换完后已经平衡了
    int res = 0;
    int left = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            left++;
        } else {
            if (left > 0) {
                left--;
            } else {
                res++;
                left++; // 换完就多一个
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minSwaps("][][") << endl;
    // 2
    cout << minSwaps("]]][[[") << endl;
    // 0
    cout << minSwaps("[]") << endl;

    return 0;
}
