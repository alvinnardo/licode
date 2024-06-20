#include "../template/head.h"
#include <bits/stdc++.h>

int countBeautifulPairs(vector<int> nums) {
    // 思路：哈希表
    // 时间 O(n2)，空间 O(k)，k 是 1 - 10 内互质对个数 * 2
    vector<unordered_set<int>> vec(10);
    for (int i = 1; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (gcd(i, j) == 1) {
                vec[i].insert(j);
                vec[j].insert(i);
            }
        }
    }

    auto getFirst = [](int t) {
        int res = 0;
        while (t) {
            res = t;
            t /= 10;
        }

        return res;
    };

    int sz = nums.size(), res = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (gcd(getFirst(nums[i]), nums[j] % 10) == 1) {
                res++;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 5
    cout << countBeautifulPairs({2, 5, 1, 4}) << endl;
    // 2
    cout << countBeautifulPairs({11, 21, 12}) << endl;

    return 0;
}
