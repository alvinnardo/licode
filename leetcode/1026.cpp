#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode() : val(0) {}
    TreeNode(int x) : val(x) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

int maxAncestorDiff(TreeNode *root) {

    int max_dis = INT_MIN;

    std::function<pair<int, int>(TreeNode *)> dfs =
        [&](TreeNode *root) -> pair<int, int> {
        if (!root->left && !root->right) {
            return {root->val, root->val};
        }

        if (!root->left || !root->right) {
            auto p = !root->left ? dfs(root->right) : dfs(root->left);
            int a = p.first;
            int b = p.second;
            int l = min(a, b);
            int r = max(a, b);
            max_dis = max(max_dis, max(abs(l - root->val), abs(r - root->val)));
            return {min(l, root->val), max(r, root->val)};
        }

        auto left_val = dfs(root->left);
        auto right_val = dfs(root->right);

        vector<int> s{left_val.first, left_val.second, right_val.first,
                      right_val.second};
        sort(s.begin(), s.end());
        max_dis = max(max_dis, max(abs(s[0] - root->val), abs(s.back() - root->val)));

        return {min(s[0], root->val), max(s.back(), root->val)};
    };

    dfs(root);
    return max_dis;
}

int main(void) {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(0);
    root->right->right->left = new TreeNode(3);
    cout << maxAncestorDiff(root) << endl;;

    return 0;
}
