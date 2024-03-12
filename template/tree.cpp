#include "head.h"
#include <bits/stdc++.h>
using namespace std;

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

    int mid_mid = INT_MIN;
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

template <class T> TreeNode<T> *buildTree(const vector<T> &vv) {
    TreeNode<T> *root = new TreeNode<T>(vv[0]);

    queue<TreeNode<T> *> qu;
    qu.push(root);
    int j = 1;

    while (!qu.empty()) {
        TreeNode<T> *top = qu.front();
        qu.pop();

        if (j >= vv.size())
            continue;
        if (vv[j] == INT_MIN) {
            top->left = nullptr;
        } else {
            top->left = new TreeNode<T>(vv[j]);
            qu.push(top->left);
        }
        j++;

        if (vv[j] == INT_MIN) {
            top->right = nullptr;
        } else {
            top->right = new TreeNode<T>(vv[j]);
            qu.push(top->right);
        }
        j++;
    }
    return root;
}

TreeNode<int> *lowestCommonAncestor(TreeNode<int> *root, TreeNode<int> *p,
                                    TreeNode<int> *q) {
    // 有一个是，就不向下找了；如果另一个也有，肯定是根，如果没有，就是当前子树
    if (!root || root == p || root == q) {
        return root;
    }

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    if (left && right) { // 左边也有，右边也有，返回根
        return root;
    }

    if (left) {
        return root->left;
    }
    return root->right; // 右子树和空合并返回结果，左边没有，右边也没有
}

// 并查集
struct UnionFind {
    vector<int> vv;
    UnionFind(int n) {
        vv.assign(n, 0);
        iota(vv.begin(), vv.end(), 0);
    }

    void unionTwo(int a, int b) {
        int fa = findX(a);
        int fb = findX(b);

        vv[fb] = fa;
    }

    int findX(int a) {
        if (vv[a] != a) {
            vv[a] = findX(vv[a]);
        }
        return vv[a];
    }

    int count() {
        int cnt = 0;
        for (int i = 0; i < vv.size(); i++) {
            if (vv[i] == i) {
                cnt++;
            }
        }
        return cnt;
    }
};

// 最小生成树
// 铺路, 连接所有城市，使铺设花费最少
// 1. 按边贪心

void testBuildTree() {
    vector<int> vv{1,       INT_MIN, 1, 1,       1,      INT_MIN,
                   INT_MIN, 1,       1, INT_MIN, 1,      INT_MIN,
                   INT_MIN, INT_MIN, 1, INT_MIN, INT_MIN};
    buildTree(vv);
}

int main(void) {
    // testBuildPreMidTree();
    UnionFind ud(10);

    return 0;
}
