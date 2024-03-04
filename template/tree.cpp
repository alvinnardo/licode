#include "../leetcode/head.h"
#include <bits/stdc++.h>
using namespace std;

template <class T> struct TreeNode {
    T val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(T x) { val = x; }
    TreeNode(T x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

template <class T> vector<T> preEnumTree(TreeNode<T> *root) {
    vector<T> res;

    function<void(TreeNode<T> *)> preOrder = [&](TreeNode<T> *root) {
        if (!root)
            return;

        res.emplace_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    };

    preOrder(root);
    return res;
}

template <class T> vector<T> midEnumTree(TreeNode<T> *root) {
    vector<T> res;

    function<void(TreeNode<T> *)> midOrder = [&](TreeNode<T> *root) {
        if (!root)
            return;

        midOrder(root->left);
        res.emplace_back(root->val);
        midOrder(root->right);
    };

    midOrder(root);
    return res;
}

template <class T> vector<T> tailEnumTree(TreeNode<T> *root) {
    vector<T> res;

    function<void(TreeNode<T> *)> tailOrder = [&](TreeNode<T> *root) {
        if (!root)
            return;

        tailOrder(root->left);
        tailOrder(root->right);
        res.emplace_back(root->val);
    };

    tailOrder(root);
    return res;
}

template <class T>
TreeNode<T> *buildPreMidTree(const vector<T> &pre_nums,
                             const vector<T> &mid_nums, int pre_left,
                             int pre_right, int mid_left, int mid_right) {
    if (pre_left > pre_right) {
        return nullptr;
    }

    T val = pre_nums[pre_left];
    TreeNode<T> *root = new TreeNode<T>(val);

    int mid_mid = -1;
    for (int i = mid_left; i <= mid_right; i++) {
        if (mid_nums[i] == val) {
            mid_mid = i;
            break;
        }
    }

    root->left =
        buildPreMidTree(pre_nums, mid_nums, pre_left + 1,
                        pre_left + mid_mid - mid_left, mid_left, mid_mid - 1);
    root->right =
        buildPreMidTree(pre_nums, mid_nums, pre_left + mid_mid - mid_left + 1,
                        pre_right, mid_mid + 1, mid_right);
    return root;
}

void testBuildPreMidTree() {
    vector<int> pre_nums{1, 2, 4, 5, 3, 6, 7};
    pre_nums = {1, 3, 6, 7};
    vector<int> mid_nums{4, 2, 5, 1, 6, 3, 7};
    mid_nums = {1, 6, 3, 7};
    TreeNode<int> *root = buildPreMidTree(
        pre_nums, mid_nums, 0, pre_nums.size() - 1, 0, mid_nums.size() - 1);

    printVector(preEnumTree(root));
    printVector(midEnumTree(root));
    printVector(tailEnumTree(root));
}

int main(void) {
    testBuildPreMidTree();

    return 0;
}
