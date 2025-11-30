#include "../template/head.h"
#include <bits/stdc++.h>

int minSubarray(vector<int> &&nums, int p) {
    // 思路：前缀和 + 贪心 + 哈希表 + 数学
    // 时间 O(n)，空间 O(n)

    // 先计算整体和对 p 取余，看多的数
    // 遍历求前缀和，在哈希表中查询前面满足的前缀和
    // 贪心选择最一次出现的值的位置

    // 例：tot = 32, p = 5, yu = 2
    // pre = 1, tail = 18(3)

    // (tot - (tail - pre)) % p = 0
    // tot % p - (tail - pre) % p = 0
    // (p + tail - pre) % p = tot % p
    // (p + tail - tot) % p = pre % p

    unordered_map<int, int> umap;
    umap[0] = 0;
    int tot{}, pre{}, need{};

    for (int i = 0; i < nums.size(); i++) {
        tot = (tot + nums[i]) % p;
    }
    if (tot == 0) { // 如果总和直接能整除，返回 0
        return 0;
    }

    int res{INT_MAX};
    for (int i = 0; i < nums.size(); i++) {
        pre = (pre + nums[i]) % p;
        need = (p + pre - tot) % p;
        // 注意不能删除整个数组，最后一个元素且需要的 0 在位置 0
        if (umap.count(need) && !(i == nums.size() - 1 && umap[need] == 0)) {
            res = min(res, i + 1 - umap[need]);
        }
        umap[pre] = i + 1;
    }

    return res == INT_MAX ? -1 : res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minSubarray({3, 1, 4, 2}, 6) << endl;
    // 2
    cout << minSubarray({6, 3, 5, 2}, 9) << endl;
    // 0
    cout << minSubarray({1, 2, 3}, 3) << endl;
    // -1
    cout << minSubarray({1, 2, 3}, 7) << endl;
    // 0
    cout << minSubarray({1000000000, 1000000000, 1000000000}, 3) << endl;

    return 0;
}
