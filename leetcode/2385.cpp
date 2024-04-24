#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//     right(right) {}
// };

int amountOfTime(TreeNode<int> *root, int start) {
    // BFS 将树转为图，BFS 层序遍历
    // 时间 O(n)，空间 O(n), 每个节点只有 3 个连接
    queue<TreeNode<int> *> qu;
    qu.push(root);
    unordered_map<int, int> umap; // 保存节点值和内部值的关系
    vector<vector<int>> edges;

    int idx = 0;
    auto getVal = [&](int i) {
        if (umap.find(i) == umap.end()) {
            umap[i] = idx++;
            edges.push_back({});
        }

        return umap[i];
    };

    // 建图
    while (!qu.empty()) {
        TreeNode<int> *t = qu.front();
        int tval = getVal(t->val);
        qu.pop();

        if (t->left) {
            int lval = getVal(t->left->val);
            edges[tval].push_back(lval);
            edges[lval].push_back(tval);
            qu.push(t->left);
        }
        if (t->right) {
            int rval = getVal(t->right->val);
            edges[tval].push_back(rval);
            edges[rval].push_back(tval);
            qu.push(t->right);
        }
    }

    // 层序遍历
    int cnt = 0;
    queue<int> quu;

    quu.push(umap[start]);

    unordered_set<int> seen;
    while (!quu.empty()) {
        int n = quu.size();
        cnt++;
        while (n--) {
            auto t = quu.front();
            quu.pop();
            if (seen.find(t) != seen.end()) {
                continue;
            }

            seen.insert(t);

            for (auto c : edges[t]) {
                if (seen.find(c) == seen.end()) {
                    quu.push(c);
                }
            }
        }
    }

    return cnt - 1;
}

int main(void) {

    TreeNode<int> *root;

    // 4
    root = buildTree(vector<int>({1, 5, 3, INT_MIN, 4, 10, 6, 9, 2}));
    cout << amountOfTime(root, 3) << endl;

    // 1
    root = buildTree(vector<int>({10000}));
    cout << amountOfTime(root, 10000) << endl;

    return 0;
}
