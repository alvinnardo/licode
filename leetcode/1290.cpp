#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：模拟
// 时间 O(n)，空间 O(1)
class Solution {
  public:
    int getDecimalValue(ListNode *head) {
        int res = 0;
        while (head) {
            res <<= 1;
            if (head->val) {
                res++;
            }
            head = head->next;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    // 5
    cout << s.getDecimalValue(buildList({1, 0, 1})) << endl;
    // 0
    cout << s.getDecimalValue(buildList({0})) << endl;

    return 0;
}
