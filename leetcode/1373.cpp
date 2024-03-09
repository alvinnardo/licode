#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int maxSubBST(TreeNode<int> *root) {
    int max_val = 0;

    // 因为下面的和上面的没有关系
    // 所以从下往上归并，如果是搜索树，那么就求和比较

    // 太牛逼了，把困难题没看题解直接做出来了，这种情况屈指可数啊
    // 看了题解，思路是一样的，太牛逼了
    function<vector<int>(TreeNode<int> *)> dfs =
        [&](TreeNode<int> *root) -> vector<int> {
        if (!root->left && !root->right) {
            max_val = max(max_val, root->val);
            return {1, root->val, root->val, root->val};
        }

        vector<int> left, right;
        int x = root->val;
        bool valid = true;
        int new_val = x;
        vector<int> res;
        if (root->left) {
            left = dfs(root->left);
            if (left[0] == 0 || x <= left[3]) {
                valid = false;
            } else {
                new_val += left[1];
                res.push_back(left[2]);
                res.push_back(left[3]);
            }
        }
        res.push_back(x);
        if (root->right) {
            right = dfs(root->right);
            if (right[0] == 0 || x >= right[2]) {
                valid = false;
            } else {
                new_val += right[1];
                res.push_back(right[2]);
                res.push_back(right[3]);
            }
        }

        if (!valid) {
            return {0, 0, 0, 0};
        }

        max_val = max(max_val, new_val);

        return {1, new_val, res.front(), res.back()};
    };

    dfs(root);
    return max_val;
}

int main(void) {
    vector<int> vv({1, 4, 3, 2, 4, 2, 5, INT_MIN, INT_MIN, INT_MIN, INT_MIN,
                    INT_MIN, INT_MIN, 4, 6});
    TreeNode<int> *root = buildTree(vv);
    // printVector(midEnumTree(root));
    cout << maxSubBST(root) << endl; // 20
    cout << maxSubBST(buildTree(vector<int>({4, 3, INT_MIN, 1, 2})))
         << endl;                                                    // 2
    cout << maxSubBST(buildTree(vector<int>({-4, -2, -5}))) << endl; // 0
    TreeNode<int> *roott = buildTree(vector<int>({2, 1, 3}));
    cout << maxSubBST(roott) << endl; // 6
    cout << maxSubBST(buildTree(vector<int>({5, 4, 8, 3, INT_MIN, 6, 3})))
         << endl; // 7
    cout << maxSubBST(buildTree(vector<int>({1, INT_MIN, 10, -5, 20})))
         << endl; // 25

    return 0;
}
