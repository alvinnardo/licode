#include "../template/head.h"
#include <bits/stdc++.h>

int maxOperations(vector<int> nums) {
    // 思路: DFS
    // 时间 O(n2)，空间 O(n2)

    int n = nums.size();
    function<int(int, int, int)> dfs = [&](int a, int b, int tot) {
        int len = b - a + 1;
        if (len <= 1) {
            return 0;
        } else if (len == 2) {
            return nums[a] + nums[b] == tot ? 1 : 0;
        } else if (len == 3) {
            if (nums[a] + nums[a + 1] == tot || nums[a] + nums[b] == tot ||
                nums[b - 1] + nums[b] == tot) {
                return 1;
            }
            return 0;
        }

        int head = nums[a] + nums[a + 1];
        int tail = nums[b - 1] + nums[b];
        int mid = nums[a] + nums[b];
        if (head == tot && tail == tot) {
            return 2 + dfs(a + 2, b - 2, tot);
        }

        int res = 0;
        if (head == tot) {
            res = max(res, 1 + dfs(a + 2, b, tot));
        }
        if (tail == tot) {
            res = max(res, 1 + dfs(a, b - 2, tot));
        }
        if (mid == tot) {
            res = max(res, 1 + dfs(a + 1, b - 1, tot));
        }

        return res;
    };

    return 1 + max(max(dfs(0, n - 3, nums[n - 2] + nums[n - 1]),
                       dfs(1, n - 2, nums[0] + nums[n - 1])),
                   dfs(2, n - 1, nums[0] + nums[1]));
}

int main(int argc, char *argv[]) {

    // 3
    cout << maxOperations({3, 2, 1, 2, 3, 4}) << endl;
    // 2
    cout << maxOperations({3, 2, 6, 1, 4}) << endl;

    return 0;
}
