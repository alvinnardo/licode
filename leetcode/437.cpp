#include "../template/head.h"
#include <bits/stdc++.h>
int pathSum(TreeNode<int> *root, int targetSum) {
    // 题解：前缀和
    // 树状 DP
    // 时间 O(n), 空间 O(n)

    unordered_map<int64_t, int> prefix;

    function<int(TreeNode<int> *, int)> dfs = [&](TreeNode<int> *root,
                                                  int tot) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        tot += root->val; // 从 root 到当前节点的和

        // 是否有区间和
        if (prefix.count(tot - targetSum)) {
            ret = prefix[tot - targetSum];
        }

        prefix[tot]++;
        ret += dfs(root->left, tot);
        ret += dfs(root->right, tot);
        prefix[tot]--;

        return ret;
    };

    prefix[0] = 1;
    return dfs(root, 0);
}

int pathSum1(TreeNode<int> *root, int targetSum) {
    // 思路：DFS，记录所有可能连续值和数量
    // 时间: O(n2), 空间 O(n)
    int cnt = 0;
    if (!root) {
        return 0;
    }

    function<unordered_map<int64_t, int>(TreeNode<int> *)> dfs =
        [&](TreeNode<int> *root) -> unordered_map<int64_t, int> {
        if (!root->left && !root->right) {
            unordered_map<int64_t, int> t;
            t[root->val] = 1;
            cnt += root->val == targetSum;
            return t;
        }

        unordered_map<int64_t, int> left, right, res;
        if (root->left) {
            left = std::move(dfs(root->left));
            for (auto &v : left) {
                res[v.first + root->val] += v.second;
            }
        }
        if (root->right) {
            right = std::move(dfs(root->right));
            for (auto &v : right) {
                res[v.first + root->val] += v.second;
            }
        }

        // 别忘了当前节点
        res[root->val]++;
        if (res.find(targetSum) != res.end()) {
            cnt += res[targetSum];
        }
        return res;
    };

    dfs(root);
    return cnt;
}

int main(int argc, char *argv[]) {
    // 3
    TreeNode<int> *root = buildTree(
        vector<int>({10, 5, -3, 3, 2, INT_MIN, 11, 3, -2, INT_MIN, 1}));
    cout << pathSum(root, 8) << endl;

    //  3
    root = buildTree(vector<int>(
        {5, 4, 8, 11, INT_MIN, 13, 4, 7, 2, INT_MIN, INT_MIN, 5, 1}));
    cout << pathSum(root, 22) << endl;

    // 1
    root = buildTree(vector<int>({5}));
    cout << pathSum(root, 5) << endl;

    // 1
    root = buildTree(vector<int>({1, 2}));
    cout << pathSum(root, 1) << endl;

    return 0;
}
