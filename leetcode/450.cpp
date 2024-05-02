#include "../template/head.h"
#include <bits/stdc++.h>

TreeNode<int> *deleteNode(TreeNode<int> *root, int key) {
    // 思路：root 上多加一层，判断左右是否是 key
    // 删除该节点，用该节点的左右子树补充；
    // 如果都是空，直接删除；
    // 如果左不是空，用左补充，把左子树的右子树放到删除节点的右子树的最左端
    // 时间 O(h), 空间 O(1)
    TreeNode<int> *fa = new TreeNode<int>(INT_MAX, root, nullptr);

    auto real_delete = [&](TreeNode<int> *root) -> TreeNode<int> * {
        if (!root->left && !root->right) {
            return nullptr;
        }

        if (root->left) {
            root->val = root->left->val;
            TreeNode<int> *tmp = root->left;
            root->left = tmp->left;
            if (!root->right) {
                root->right = tmp->right;
            } else {
                if (!root->right->left) {
                    root->right->left = tmp->right;
                } else {
                    TreeNode<int> *tt = root->right->left;
                    while (tt->left) {
                        tt = tt->left;
                    }
                    tt->left = tmp->right;
                }
            }

        } else {
            root->val = root->right->val;
            TreeNode<int> *tmp = root->right;
            root->right = tmp->right;
            if (!root->left) {
                root->left = tmp->left;
            } else {
                if (!root->left->right) {
                    root->left->right = tmp->left;
                } else {
                    TreeNode<int> *tt = root->left->right;
                    while (tt->right) {
                        tt = tt->right;
                    }
                    tt->right = tmp->left;
                }
            }
        }

        return root;
    };

    function<void(TreeNode<int> *)> dfs = [&](TreeNode<int> *cur) {
        if (!cur->left && !cur->right) {
            return;
        }

        if (cur->left && key < cur->val) {
            if (key == cur->left->val) {
                cur->left = real_delete(cur->left);
            } else {
                dfs(cur->left);
            }
        }

        if (cur->right && key > cur->val) {
            if (key == cur->right->val) {
                cur->right = real_delete(cur->right);
            } else {
                dfs(cur->right);
            }
        }
    };

    dfs(fa);
    return fa->left;
}

int main(int argc, char *argv[]) {
    TreeNode<int> *root = buildTree(vector<int>({5, 3, 6, 2, 4, INT_MIN, 7}));
    // printVector(preEnumTree(deleteNode(root, 5)));
    // printVector(preEnumTree(deleteNode(root, 3)));
    // printVector(preEnumTree(deleteNode(root, 6)));
    // printVector(preEnumTree(deleteNode(root, 2)));
    // printVector(preEnumTree(deleteNode(root, 4)));
    // printVector(preEnumTree(deleteNode(root, 7)));
    // printVector(preEnumTree(deleteNode(root, 7)));
    root = buildTree(vector<int>(
        {10,      5, 15,      3,       8,       13, 19,      1,       4,
         7,       9, 12,      INT_MIN, 17,      21, INT_MIN, INT_MIN, INT_MIN,
         INT_MIN, 6, INT_MIN, INT_MIN, INT_MIN, 11, INT_MIN, 16,      18}));
    printVector(preEnumTree(deleteNode(root, 10)));

    root = buildTree(vector<int>({}));
    printVector(preEnumTree(deleteNode(root, 7)));

    return 0;
}
