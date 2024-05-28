
#include "../template/head.h"
#include <bits/stdc++.h>

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

TreeNode<int> *convertBST(TreeNode<int> *root) {
    // 思路：右中左遍历
    int sum = 0;

    function<void(TreeNode<int> *)> dfs = [&](TreeNode<int> *node) {
        if (!node) {
            return;
        }

        dfs(node->right);
        node->val += sum;
        sum = node->val;
        dfs(node->left);
    };

    dfs(root);
    return root;
}

int main(int argc, char *argv[]) {

    TreeNode<int> *root =
        buildTree(vector<int>({4, 1, 6, 0, 2, 5, 7, INT_MIN, INT_MIN, INT_MIN,
                               3, INT_MIN, INT_MIN, INT_MIN, 8}));
    printVector(midEnumTree(convertBST(root)));
    return 0;
}
