#include "../template/head.h"
#include <bits/stdc++.h>

int peopleAwareOfSecret(int n, int delay, int forget) {
    // 思路：前缀和
    // 时间 O(n)，空间 O(n)

    // 从某一天开始一直加，从某一天开始取消
    // 如果忘记，则人数要减 1，还要取消
    const long long mod = 1e9 + 7;

    vector<long long> inc_vec(n); //  保存每天实际增加的人数，差分求前缀和
    vector<long long> dec_vec(n); // 保存每天需要减少的人数

    // 处理第一个人
    if (delay < n) {
        inc_vec[delay]++;
    }
    if (forget < n) {
        inc_vec[forget]--;
        dec_vec[forget]--;
    }
    long long sum{1};

    for (int i = 1; i < n; i++) {
        inc_vec[i] += inc_vec[i - 1];
        if (inc_vec[i] > 0) {
            int t = i + delay;
            if (t < n) {
                inc_vec[t] = (inc_vec[t] + inc_vec[i]) % mod;
            }
            t = i + forget;
            if (t < n) {
                inc_vec[t] = (inc_vec[t] - inc_vec[i] + mod) % mod;
                dec_vec[t] = (dec_vec[t] - inc_vec[i] + mod) % mod;
            }
        }

        // 求每天的结果，需要加上每天实际增加的人数，和需要减少的人数(就是忘记的人数)
        sum = (mod + sum + inc_vec[i] + dec_vec[i]) % mod;
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 5
    cout << peopleAwareOfSecret(6, 2, 4) << endl;
    // 6
    cout << peopleAwareOfSecret(4, 1, 3) << endl;

    return 0;
}
