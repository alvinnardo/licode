#include "../template/head.h"
#include <bits/stdc++.h>

bool isMatch(TreeNode *root, TreeNode *subRoot) {
    if (!root && !subRoot) {
        return true;
    } else if (!root || !subRoot) {
        return false;
    }

    return root->val == subRoot->val && isMatch(root->left, subRoot->left) &&
           isMatch(root->right, subRoot->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    // 思路：遍历
    // 时间 O(mn)，空间 O(m)
    queue<TreeNode *> qu;
    qu.push(root);

    while (!qu.empty()) {
        TreeNode *t = qu.front();
        qu.pop();

        if (isMatch(t, subRoot)) {
            return true;
        }

        if (t->left) {
            qu.push(t->left);
        }
        if (t->right) {
            qu.push(t->right);
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    // 1
    TreeNode *root = buildTree({3, 4, 5, 1, 2}), *root2 = buildTree({4, 1, 2});
    cout << isSubtree(root, root2) << endl;

    // 0
    root = buildTree({3, 4, 5, 1, 2, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0});
    root2 = buildTree({4, 1, 2});
    cout << isSubtree(root, root2) << endl;

    return 0;
}
