#include "../template/head.h"
#include <bits/stdc++.h>

int averageOfSubtree(TreeNode *root) {
    // 思路：DFS
    // 时间 O(n)，空间 O(n)

    int cnt = 0;

    // {个数，和}
    function<pair<int, int>(TreeNode *)> dfs =
        [&](TreeNode *cur) -> pair<int, int> {
        if (!cur) {
            return {0, 0};
        }

        auto left = dfs(cur->left);
        auto right = dfs(cur->right);
        left.first = left.first + right.first + 1;
        left.second = left.second + right.second + cur->val;
        cnt += (left.second / left.first == cur->val);

        return left;
    };

    dfs(root);
    return cnt;
}

int main(int argc, char *argv[]) {
    // 5
    cout << averageOfSubtree(buildTree({4, 8, 5, 0, 1, INT_MIN, 6})) << endl;
    // 1
    cout << averageOfSubtree(buildTree({1})) << endl;

    return 0;
}
