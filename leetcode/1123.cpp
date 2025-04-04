#include "../template/head.h"
#include <bits/stdc++.h>

TreeNode *lcaDeepestLeaves(TreeNode *root) {
    // 思路：DFS
    // 时间 O(n)，空间 O(logn)

    // 如果 左边的最大深度 = 右边的最大深度
    // 则是一个公共的节点，从下往上，则最后一个就是最终的节点
    int depth = -1;
    TreeNode *res = nullptr;

    function<int(TreeNode *, int)> dfs = [&](TreeNode *cur, int level) {
        int left = cur->left ? dfs(cur->left, level + 1) : level;
        int right = cur->right ? dfs(cur->right, level + 1) : level;
        if (left == right) {
            if (left > depth || left == depth) {
                depth = left;
                res = cur;
            }
        }

        return max(left, right);
    };

    dfs(root, 0);
    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << lcaDeepestLeaves(
                buildTree({3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 8, 4}))
                ->val
         << endl;
    // 1
    cout << lcaDeepestLeaves(buildTree({1}))->val << endl;
    // 2
    cout << lcaDeepestLeaves(buildTree({0, 1, 3, INT_MIN, 2}))->val << endl;

    return 0;
}
