#include "../template/head.h"
#include <bits/stdc++.h>

int numFactoredBinaryTrees(vector<int> arr) {
    // 思路：哈希表
    // 时间 O(nlogn)，空间 O(n)

    const int mod = 1e9 + 7;
    // 先排序，方便顺序查因子
    sort(arr.begin(), arr.end());
    unordered_map<int, long long> umap;

    long long res = 0;
    for (int a : arr) {
        // 找因子，logn 即可
        int lg = sqrt(a);
        long long cnt = 0;

        for (int b : arr) {
            if (b > lg) {
                break;
            }
            if (a % b == 0) {
                int other = a / b;
                // 如果左右数字相同，乘以 2 即可
                if (umap[b] && umap[other]) {
                    long long t = (umap[b] * umap[other]) % mod;
                    if (b != other) {
                        t = (t << 1) % mod;
                    }
                    cnt = (cnt + t) % mod;
                }
            }
        }

        cnt++;
        umap[a] = (umap[a] + cnt) % mod;
        res = (res + cnt) % mod;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << numFactoredBinaryTrees({2, 4}) << endl;
    // 7
    cout << numFactoredBinaryTrees({2, 4, 5, 10}) << endl;
    // 23
    cout << numFactoredBinaryTrees({2, 4, 5, 8, 10, 20}) << endl;

    return 0;
}
