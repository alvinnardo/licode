#include "../template/head.h"
#include <bits/stdc++.h>

class Solution {
  public:
    // 思路：模拟
    // 时间 O(n * 2^m)，空间 O(height)
    bool test(ListNode *head, TreeNode *root) {
        if (!head) {
            return true;
        } else if (head && root) {
            if (head->val == root->val) {
                return test(head->next, root->left) ||
                       test(head->next, root->right);
            }
            return false;
        }

        return false;
    }

    bool isSubPath(ListNode *head, TreeNode *root) {

        return test(head, root) ||
               (root->left && isSubPath(head, root->left)) ||
               (root->right && isSubPath(head, root->right));
    }
};

int main(int argc, char *argv[]) {

    TreeNode *root = buildTree({1, 4, 4, INT_MIN, 2, 2, INT_MIN, 1, INT_MIN, 6,
                                8, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 1, 3});

    ListNode *head = buildList({4, 2, 8});

    Solution s;
    cout << s.isSubPath(head, root) << endl;

    return 0;
}
