#include <bits/stdc++.h>
using namespace std;

template <class T> struct TreeNode {
    T val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode() : val(0) {}
    TreeNode(T x) : val(x) {}
    TreeNode(T x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

template <class T> TreeNode<T> *buildTree(const vector<T> &vv) {
    TreeNode<T> *root = new TreeNode<T>(vv[0]);

    queue<TreeNode<T> *> qu;
    qu.push(root);
    int j = 1;

    while (!qu.empty()) {
        TreeNode<T> *top = qu.front();
        qu.pop();

        if (j >= vv.size()) continue;

        if (vv[j] == -1) {
            top->left = nullptr;
        } else {
            top->left = new TreeNode<T>(vv[j]);
            qu.push(top->left);
        }
        j++;

        if (vv[j] == -1) {
            top->right = nullptr;
        } else {
            top->right = new TreeNode<T>(vv[j]);
            qu.push(top->right);
        }
        j++;
    }
    return root;
}

int longZigZag(TreeNode<int> *root) {
    int max_len = 0;
    function<void(TreeNode<int> *, int, int)> dfs = [&](TreeNode<int> *root,
                                                        int left, int len) {
        if (!root) {
            return;
        }
        max_len = max(max_len, len);

        if (left) { // 规定按左走
            dfs(root->left, 0, len + 1); // 按规定走 
            dfs(root->right, 1, 1); // 偏要反着来
        } else { // 规定按右走
            dfs(root->right, 1, len + 1); // 按规定走
            dfs(root->left, 0, 1); // 偏要反着来
        }
    };

    dfs(root, 0, 0);
    dfs(root, 1, 0);
    return max_len;
}

int main(void) {
    vector<int> vv{1, -1, 2, 3, 4, -1, -1, 5, 6, -1, 7, -1, -1, -1, 8, -1, -1};
    // vv = {6,  9,  7,  3,  -1, 2,  8,  5,  8,  9,  7,  3,  9,  9,  4,  2,
    //       10, -1, 5,  4,  3,  10, 10, 9,  4,  1,  2,  -1, -1, 6,  5,  -1,
    //       -1, -1, -1, 9,  -1, 9,  6,  5,  -1, 5,  -1, -1, 7,  7,  4,  -1,
    //       1,  -1, -1, 3,  7,  -1, 9,  -1, -1, -1, -1, -1, -1, -1, -1, 9,
    //       9,  -1, -1, -1, 7,  -1, -1, -1, -1, -1, -1, -1, -1, -1, 6,  8,
    //       7,  -1, -1, -1, 3,  10, -1, -1, -1, -1, -1, 1,  -1, 1,  2};
    TreeNode<int> *root = buildTree(vv);
    cout << longZigZag(root) << endl;

    return 0;
}
