#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：DFS
// 时间 O(n)，空间 O(n)
class BSTIterator {
  public:
    vector<int> m_res;
    int pos = 0;
    BSTIterator(TreeNode *root) { createTree(root); }
    void createTree(TreeNode *root) {
        if (!root) {
            return;
        }
        createTree(root->left);
        m_res.emplace_back(root->val);
        createTree(root->right);
    }

    int next() { return m_res[pos++]; }

    bool hasNext() { return pos != m_res.size(); }
};

int main(int argc, char *argv[]) {
    BSTIterator *bSTIterator =
        new BSTIterator(buildTree({7, 3, 15, INT_MIN, INT_MIN, 9, 20}));
    cout << bSTIterator->next() << endl;    // 3
    cout << bSTIterator->next() << endl;    // 7
    cout << bSTIterator->hasNext() << endl; // True
    cout << bSTIterator->next() << endl;    // 9
    cout << bSTIterator->hasNext() << endl; // True
    cout << bSTIterator->next() << endl;    // 15
    cout << bSTIterator->hasNext() << endl; // True
    cout << bSTIterator->next() << endl;    // 20
    cout << bSTIterator->hasNext() << endl; // False

    return 0;
}
