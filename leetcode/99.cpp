#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// 空间 O(1)，自己的算法
void recoverTree(TreeNode<int> *root) {
    // 可以直接在遍历中得到排序错误的值
    // 第一个大于异常值是前面的，第二个大于异常值是后面的
    bool ba = false;
    TreeNode<int> *pre = nullptr, *a = nullptr, *b = nullptr; // 直接保存指针
    function<void(TreeNode<int> *)> dfs = [&](TreeNode<int> *root) {
        if (!root)
            return;

        dfs(root->left);
        if (pre != nullptr) {
            if (pre->val > root->val) {
                if (ba == false) {
                    ba = true;
                    a = pre;  // 第一次异常，取前面
                    b = root; // 第二次没异常，就是目前这俩
                } else {
                    b = root; // 第二次异常，取后面
                }
            }
        }
        pre = root;
        dfs(root->right);
    };

    dfs(root);
    int t = a->val;
    a->val = b->val;
    b->val = t;
}

void recoverTree_ori(TreeNode<int> *root) {
    vector<int> vec;
    int pa = -1, pb = -1;
    int a, b;
    function<void(TreeNode<int> *)> dfs = [&](TreeNode<int> *root) {
        if (!root)
            return;

        dfs(root->left);
        if (pa == -1 && pb == -1) {
            vec.push_back(root->val);
        } else {
            if (root->val == a) {
                root->val = b;
            } else if (root->val == b) {
                root->val = a;
            }
        }
        dfs(root->right);
    };

    dfs(root);
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            if (pa == -1) {
                pa = i;
            } else {
                pb = i + 1;
            }
        }
    }

    a = vec[pa];
    b = pb == -1 ? vec[pa + 1] : vec[pb];
    // cout << a << " " << b << endl;
    dfs(root);
}

int main(void) {
    vector<int> vec{1, 3, INT_MIN, INT_MIN, 2};
    TreeNode<int> *root = buildTree(vec);
    // vector<int> vec = {3, 1, 4, INT_MIN, INT_MIN, 2};
    // TreeNode<int> *root = buildTree(vec);
    printVector(midEnumTree(root));
    recoverTree(root);
    printVector(midEnumTree(root));
    cout << INT_MIN << endl;

    return 0;
}
