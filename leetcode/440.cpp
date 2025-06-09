#include "../template/head.h"
#include <bits/stdc++.h>

int findKthNumber(int n, int k) {
    // 思路：找规律
    // 时间 O(mlogn)，空间 O(m), m = 10

    // 每次对领头的数字进行展开
    // 比如第一次 1,2,3..9，如果头部一样则可以相减获得
    // 然后获取在某一组的第几个

    string s = to_string(n);

    int res = 0, pre = 0, ret = n;
    bool pre_match = false;

    int t = 0;
    for (int i = 0; i < s.length(); i++) {
        t = t * 10 + 1;
    }
    for (int p = 0; p < s.length(); p++) {

        int sum = 0;
        vector<int> vec(10);
        char c = '0';
        bool trans = false;
        for (int i = p == 0 ? 1 : 0; i < 10; i++) {
            c = '0' + i;
            if (c == s[p]) { // 不计算
                if (p == 0) {
                    trans = true;
                } else if (pre_match) {
                    trans = true;
                } else {
                    vec[i] = trans ? t / 10 : t;
                    sum += vec[i];
                }
            } else {
                vec[i] = trans ? t / 10 : t;
                sum += vec[i];
            }
        }

        if (trans) {
            vec[s[p] - '0'] = ret - sum;
        }

        for (int i = 0; i < 10; i++) {
            if (pre + vec[i] >= k) { // 在这里面，需要继续展开
                res = res * 10 + i;  // 最终的结果的下一位就是它
                ret = vec[i] - 1;
                pre++;
                if (i == (s[p] - '0')) {
                    if (p == 0) {
                        pre_match = true;
                    }
                } else {
                    pre_match = false;
                }

                t = !pre_match ? vec[i] / 10 : vec[i] / 100;

                break;
            } else {
                pre += vec[i];
            }
        }

        if (pre == k) {
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 10
    cout << findKthNumber(13, 2) << endl;
    // 1
    cout << findKthNumber(1, 1) << endl;
    // 13
    cout << findKthNumber(20, 5) << endl;
    // 9
    cout << findKthNumber(20, 20) << endl;
    // cout << findKthNumber(100, 15) << endl;
    // for (int t = 10; t < 20; t++) {
    int t = 123;
    cout << "t: " << t << endl;
    for (int i = 1; i <= t; i++) {
        cout << findKthNumber(t, i) << endl;
    }
    // }

    return 0;
}
