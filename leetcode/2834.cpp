#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int minimumPossibleSum(int n, int target) {

    // 数量级是 1e9, O(n) 的算法也会特别慢
    // 所以必须要找到 O(logn) 或 O(1) 的算法
    // 经过分析，总之就是一个公差为 1 的等差数列求和
    // 需要注意的是，利用 target / 2，可以求得 1 .. target / 2 是要枚举的
    // target / 2 + 1 .. target - 1 是跳过的数字
    // 根据这个思想，就能把最后的结果分解成两部分求和公式
    // 接下来就是对求和进行优化，因为数量级会导致乘法溢出，直接采用 long long

    cout << "=== n: " << n << ", target: " << target << endl;
    auto getSum = [](int a, int b) -> long long {
        long long add = a; add += b;
        long long cnt = b; cnt = cnt - a + 1;

        return add * cnt / 2;
    };
    int left = (target >> 1) + 1;
    int right = target - 1;

    // 求重合的个数
    int cnt = 0;
    if (left <= n) {
        if (right <= n) {
            cnt = (n - left + 1) - (n - right + 1) + 1;
        } else {
            cnt = (n - left + 1);
        }
    }
    // 不能从 n 往后接，要从 cnt 往后接
    // 比如 n = 37，target = 46，如果 接了 38 那么，之前的 8 就冲突了
    long long res = getSum(1, n);
    if (cnt > 0) {
        if (n < right)
            res += getSum(right + 1, right + cnt);
        else {
            res += getSum(n + 1, n + cnt);
        }
        res -= getSum(left, left + cnt - 1);
    }

    return res % mod;
}

int minimumPossibleSum_bak(int n, int target) {
    // 贪心，a + b = target
    // 假设 a < b，如果 a 存在，那么 b 不存在；如果 a 不存在，b 可能存在
    // 肯定前者总和更小
    int cur = 1;
    unordered_set<int> uset;
    int64_t tot = 0;

    int i = 0;
    while (i < n) {
        // cout << i << endl;
        if (uset.find(cur) == uset.end()) {
            tot = (tot + cur) % mod;
            int remain = target - cur;
            if (remain > 0) {
                uset.insert(remain);
            }
            i++;
            cur++;
        } else {
            cur++;
        }
    }
    return tot;
}

int main(void) {
    cout << minimumPossibleSum(2, 3) << endl;   // 4
    cout << minimumPossibleSum(3, 3) << endl;   // 8
    cout << minimumPossibleSum(1, 3) << endl;   // 1
    cout << minimumPossibleSum(1, 1e9) << endl; // 1
    cout << minimumPossibleSum(37, 46) << endl; // 1011
    cout << minimumPossibleSum(1000000000, 100000) << endl; // 499700049
    cout << minimumPossibleSum(1000000000, 1000000) << endl; // 997001785
    // cout << minimumPossibleSum(1000000000, 1000000000) << endl;

    return 0;
}
