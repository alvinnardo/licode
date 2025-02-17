#include "../template/head.h"
#include <bits/stdc++.h>
TreeNode *expandBinaryTree(TreeNode *root) {
    // 思路：DFS
    // 转为迭代
    // 时间 O(n)，空间 O(1)
    queue<TreeNode *> qu;
    qu.emplace(root);

    while (!qu.empty()) {
        auto t = qu.front();
        qu.pop();

        if (t->left) {
            t->left = new TreeNode(-1, t->left, nullptr);
            qu.emplace(t->left->left);
        }

        if (t->right) {
            t->right = new TreeNode(-1, nullptr, t->right);
            qu.emplace(t->right->right);
        }
    }

    return root;
}

TreeNode *expandBinaryTree_dfs(TreeNode *root) {
    // 思路：DFS
    // 时间 O(n)，空间 O(1)

    function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
        if (!cur) {
            return;
        }

        if (cur->left) {
            // 优化空间，两步简化为一步
            cur->left = new TreeNode(-1, cur->left, nullptr);
            dfs(cur->left->left);
        }
        if (cur->right) {
            cur->right = new TreeNode(-1, nullptr, cur->right);
            dfs(cur->right->right);
        }
    };

    dfs(root);
    return root;
}

int main(int argc, char *argv[]) {
    // {7,-1,-1,5,null,null,6}
    TreeNode *root = buildTree({7, 5, 6});
    printVector(levelEnumTree(expandBinaryTree(root)));

    // {3,-1,-1,1,null,null,7,-1,-1,null,-1,3,null,null,8,null,4}
    root = buildTree({3, 1, 7, 3, 8, INT_MIN, 4});
    printVector(levelEnumTree(expandBinaryTree(root)));

    return 0;
}
