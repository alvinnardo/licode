#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    // 思路：层序遍历
    // 时间 O(n)，空间 O(n)

    vector<vector<int>> edges(501);
    queue<TreeNode *> qu;
    qu.push(root);

    // 树 转 图
    while (!qu.empty()) {
        TreeNode *t = qu.front();
        qu.pop();

        if (t->left) {
            edges[t->val].push_back(t->left->val);
            edges[t->left->val].push_back(t->val);
            qu.push(t->left);
        }
        if (t->right) {
            edges[t->val].push_back(t->right->val);
            edges[t->right->val].push_back(t->val);
            qu.push(t->right);
        }
    }

    // 层序遍历
    unordered_set<int> uset;
    queue<int> qqu;
    qqu.push(target->val);

    int cur = 0;
    while (cur++ < k) {
        int sz = qqu.size();
        if (sz == 0) {
            break;
        }

        while (sz--) {
            int t = qqu.front();
            qqu.pop();
            if (uset.count(t)) {
                continue;
            }
            uset.insert(t);

            for (auto e : edges[t]) {
                qqu.push(e);
            }
        }
    }

    vector<int> res;
    while (!qqu.empty()) {
        int t = qqu.front();
        qqu.pop();
        if (uset.count(t)) {
            continue;
        }
        uset.insert(t);
        res.push_back(t);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {7,4,1}
    printVector(
        distanceK(buildTree({3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4}),
                  new TreeNode(5), 2));
    // {}
    printVector(distanceK(buildTree({1}), new TreeNode(1), 3));

    // {}
    printVector(distanceK(buildTree({1}), new TreeNode(1), 0));

    return 0;
}
