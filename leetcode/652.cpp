#include "../template/head.h"
#include <bits/stdc++.h>

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    // 题解2：用序号替换子树，题解用哈希表存三元组
    // 我改换用字符串保存, 用序号替换能减少时间和空间复杂度
    // 时间 O(n)，空间 O(n)

    unordered_map<string, int> umap;        // 保存序列化和下标的关系
    unordered_map<int, TreeNode *> visited; // 保存重复下标和节点的关系

    int idx = 1;
    function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int {
        if (!root) {
            return 0;
        }

        string serial_str = to_string(root->val) + "(" +
                            to_string(dfs(root->left)) + ")" + "(" +
                            to_string(dfs(root->right)) + ")";
        if (!umap.count(serial_str)) {
            umap[serial_str] = idx++;
        } else {
            visited[umap[serial_str]] = root; // 把重复下标的节点存下来
        }

        return umap[serial_str];
    };

    dfs(root);
    vector<TreeNode *> res;
    for (auto &it : visited) {
        res.push_back(it.second);
    }
    return res;
}

vector<TreeNode *> findDuplicateSubtrees1(TreeNode *root) {
    // 题解1：DFS + 前序序列化
    // 时间 O(n2)，空间 O(n2)

    unordered_map<string, int> umap;
    vector<TreeNode *> repeat;

    function<string(TreeNode *)> dfs = [&](TreeNode *root) -> string {
        if (!root) {
            return "";
        }

        string serial_str = to_string(root->val) + "(" + dfs(root->left) + ")" +
                            "(" + dfs(root->right) + ")";
        if (++umap[serial_str] == 2) {
            repeat.push_back(root);
        }

        return serial_str;
    };

    dfs(root);
    return repeat;
}

vector<TreeNode *> findDuplicateSubtrees_my(TreeNode *root) {

    // 思路：点点比较
    // 时间 O(n2)，空间 O(n)
    unordered_set<TreeNode *> uset;
    queue<TreeNode *> qu;
    qu.push(root);

    function<bool(TreeNode * left, TreeNode * right)> isEqual =
        [&](TreeNode *left, TreeNode *right) {
            if (!left && !right) {
                return true;
            }
            if (!left || !right) {
                return false;
            }

            return (left->val == right->val &&
                    isEqual(left->left, right->left) &&
                    isEqual(left->right, right->right));
        };

    unordered_set<TreeNode *> uuset;
    function<void(TreeNode *)> pushTree = [&](TreeNode *root) {
        if (!root) {
            return;
        }

        uuset.insert(root);
        pushTree(root->left);
        pushTree(root->right);
    };

    unordered_set<TreeNode *> visited;
    while (!qu.empty()) {
        TreeNode *cur = qu.front();
        qu.pop();

        if (uset.count(cur)) {
            continue;
        }

        queue<TreeNode *> qqu;
        qqu.push(root);
        while (!qqu.empty()) {
            TreeNode *ccur = qqu.front();
            qqu.pop();

            if (ccur == cur || uset.count(ccur)) {
                continue;
            }

            if (!visited.count(ccur) && isEqual(cur, ccur)) {
                uset.insert(cur);
                uset.insert(ccur);
                pushTree(cur);
            }

            if (ccur->left) {
                qqu.push(ccur->left);
            }
            if (ccur->right) {
                qqu.push(ccur->right);
            }
        }

        visited.insert(cur);
        if (cur->left) {
            qu.push(cur->left);
        }
        if (cur->right) {
            qu.push(cur->right);
        }
    }

    vector<TreeNode *> vec(uuset.begin(), uuset.end());
    vector<TreeNode *> res;
    for (int i = 0; i < vec.size(); i++) {
        int cnt = 0;
        for (int j = i + 1; j < vec.size(); j++) {
            if (isEqual(vec[i], vec[j])) {
                cnt++;
            }
        }

        if (cnt == 0) {
            res.push_back(vec[i]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << findDuplicateSubtrees(
                buildTree({1, 2, 3, 4, INT_MIN, 2, 4, INT_MIN, INT_MIN, 4}))
                .size()
         << endl;
    // 1
    cout << findDuplicateSubtrees(buildTree({2, 1, 1})).size() << endl;
    // 2
    cout << findDuplicateSubtrees(buildTree({2, 2, 2, 3, INT_MIN, 3, INT_MIN}))
                .size()
         << endl;
    // 6
    cout << findDuplicateSubtrees(
                buildTree({1,       2,       4,       3,       INT_MIN, 6,
                           5,       INT_MIN, INT_MIN, 2,       INT_MIN, 2,
                           6,       3,       INT_MIN, 3,       INT_MIN, 2,
                           INT_MIN, 7,       INT_MIN, INT_MIN, INT_MIN, 3,
                           INT_MIN, INT_MIN, INT_MIN, 7}))
                .size()
         << endl;

    return 0;
}
