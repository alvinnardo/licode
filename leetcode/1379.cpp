#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                        TreeNode *target) {

    // 对两棵树同时做层序遍历
    queue<TreeNode *> qu1, qu2;
    qu1.push(original);
    qu2.push(cloned);

    while (!qu1.empty()) {

        TreeNode *t = qu1.front();
        TreeNode *t2 = qu2.front();
        qu1.pop();
        qu2.pop();
        if (t == target) {
            return t2;
        }

        if (t->left) {
            qu1.push(t->left);
            qu2.push(t2->left);
        }
        if (t->right) {
            qu1.push(t->right);
            qu2.push(t2->right);
        }
    }
    return nullptr;
}

int main(void) { return 0; }
