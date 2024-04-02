#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

vector<TreeNode *> allPossibleFBT(int n) {
    vector<vector<TreeNode *>> dp(n + 1);
    // 0 是 空, 1 是 单个节点
    TreeNode *t = new TreeNode(0);
    dp[1].emplace_back(t);

    for (int i = 3; i <= n; i += 2) {
        int t = i - 1;
        for (int j = 1; j < t; j += 2) {
            auto left = dp[j];
            auto right = dp[t - j];
            for (int p = 0; p < left.size(); p++) {
                for (int q = 0; q < right.size(); q++) {
                    TreeNode *t = new TreeNode(0, left[p], right[q]);
                    dp[i].emplace_back(t);
                }
            }
        }
    }

    return dp[n];
}

int main(void) {
    for (int i = 1; i <= 20; i++) {
        cout << i << ": " << allPossibleFBT(i).size() << endl;
    }
    return 0;
}
