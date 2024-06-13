#include "../template/head.h"
#include <bits/stdc++.h>

int longestUnivaluePath(TreeNode *root) {
    // 思路：DFS，每个节点返回以当前节点为起点的最长长度
    // 时间 O(n)，空间 O(n)，调用栈最坏情况下是 O(n)
    if (!root) {
        return 0;
    }

    int maxv = INT_MIN;

    function<pair<int, int>(TreeNode *)> dfs =
        [&](TreeNode *root) -> pair<int, int> {
        if (!root->left && !root->right) {
            maxv = max(maxv, 1);
            return {root->val, 1};
        }

        pair<int, int> left, right;
        int cnt = 1;
        if (root->left) {
            left = dfs(root->left);
            if (root->val == left.first) {
                cnt = max(cnt, left.second + 1);
            }
        }
        if (root->right) {
            right = dfs(root->right);
            if (root->val == right.first) {
                cnt = max(cnt, right.second + 1);
            }
        }

        if (root->left && root->right && root->val == left.first &&
            root->val == right.first) {
            maxv = max(maxv, left.second + right.second + 1);
        }
        maxv = max(maxv, cnt);

        return {root->val, cnt};
    };

    dfs(root);
    return maxv - 1;
}

int main(int argc, char *argv[]) {
    // 2
    cout << longestUnivaluePath(buildTree({5, 4, 5, 1, 1, 5})) << endl;
    // 2
    cout << longestUnivaluePath(buildTree({1, 4, 5, 4, 4, 5})) << endl;

    return 0;
}
