#include "../template/head.h"
#include <bits/stdc++.h>

int longestCycle(vector<int> edges) {
    // 思路：双指针 + 哈希表
    // 时间 O(n)，空间 O(n)

    // 快慢指针
    // 1. 都走完一步，如果相遇，则找到起点
    // 2. 如果快指针走到空，则这条路没有环，慢指针走到头
    // 3. 如果相遇，则慢指针再走一圈，得到长度
    // 4. 使用哈希表存放已经走过的路径，如果慢指针走重复了，则这条路之前走过

    int res = -1, n = edges.size();
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        int fast = i, slow = i;

        bool match = false;
        // 注意这里都用 != -1，有时候会忘掉 0 也是有效的下标
        while (edges[fast] != -1 && edges[edges[fast]] != -1) {
            if (vec[slow]) { // 之前走过了
                break;
            }

            fast = edges[edges[fast]];
            slow = edges[slow];

            if (fast == slow) {
                match = true;
                break;
            }
        }

        // 把没走过的走一遍
        if (match) {
            int cnt = 0, t = slow;
            while (slow != -1 && !vec[slow]) {
                vec[slow] = 1;
                slow = edges[slow];
                cnt++;
                if (slow == t) {
                    break;
                }
            }
            res = max(res, cnt);
        } else {
            while (slow != -1 && !vec[slow]) {
                vec[slow] = 1;
                slow = edges[slow];
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << longestCycle({3, 3, 4, 2, 3}) << endl;
    // -1
    cout << longestCycle({2, -1, 3, 1}) << endl;
    // 2
    cout << longestCycle({1, 0}) << endl;

    return 0;
}
