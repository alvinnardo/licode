#include "head.h"
#include <bits/stdc++.h>
using namespace std;

template <class T> vector<T> preEnumTree(TreeNode<T> *root) {
    vector<T> res;

    function<void(TreeNode<T> *)> preOrder = [&](TreeNode<T> *root) {
        if (!root)
            return;

        res.emplace_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    };

    preOrder(root);
    return res;
}

template <class T> vector<T> midEnumTree(TreeNode<T> *root) {
    vector<T> res;

    function<void(TreeNode<T> *)> midOrder = [&](TreeNode<T> *root) {
        if (!root)
            return;

        midOrder(root->left);
        res.emplace_back(root->val);
        midOrder(root->right);
    };

    midOrder(root);
    return res;
}

template <class T> vector<T> tailEnumTree(TreeNode<T> *root) {
    vector<T> res;

    function<void(TreeNode<T> *)> tailOrder = [&](TreeNode<T> *root) {
        if (!root)
            return;

        tailOrder(root->left);
        tailOrder(root->right);
        res.emplace_back(root->val);
    };

    tailOrder(root);
    return res;
}

template <class T>
TreeNode<T> *buildPreMidTree(const vector<T> &pre_nums,
                             const vector<T> &mid_nums, int pre_left,
                             int pre_right, int mid_left, int mid_right) {
    if (pre_left > pre_right) {
        return nullptr;
    }

    T val = pre_nums[pre_left];
    TreeNode<T> *root = new TreeNode<T>(val);

    int mid_mid = INT_MIN;
    for (int i = mid_left; i <= mid_right; i++) {
        if (mid_nums[i] == val) {
            mid_mid = i;
            break;
        }
    }

    root->left =
        buildPreMidTree(pre_nums, mid_nums, pre_left + 1,
                        pre_left + mid_mid - mid_left, mid_left, mid_mid - 1);
    root->right =
        buildPreMidTree(pre_nums, mid_nums, pre_left + mid_mid - mid_left + 1,
                        pre_right, mid_mid + 1, mid_right);
    return root;
}

void testBuildPreMidTree() {
    vector<int> pre_nums{1, 2, 4, 5, 3, 6, 7};
    pre_nums = {1, 3, 6, 7};
    vector<int> mid_nums{4, 2, 5, 1, 6, 3, 7};
    mid_nums = {1, 6, 3, 7};
    TreeNode<int> *root = buildPreMidTree(
        pre_nums, mid_nums, 0, pre_nums.size() - 1, 0, mid_nums.size() - 1);

    printVector(preEnumTree(root));
    printVector(midEnumTree(root));
    printVector(tailEnumTree(root));
}

template <class T> TreeNode<T> *buildTree(vector<T> vv) {
    TreeNode<T> *root = new TreeNode<T>(vv[0]);

    queue<TreeNode<T> *> qu;
    qu.push(root);
    int j = 1;

    while (!qu.empty()) {
        TreeNode<T> *top = qu.front();
        qu.pop();

        if (j >= vv.size())
            continue;
        if (vv[j] == INT_MIN) {
            top->left = nullptr;
        } else {
            top->left = new TreeNode<T>(vv[j]);
            qu.push(top->left);
        }
        j++;

        if (j >= vv.size()) {
            continue;
        }
        if (vv[j] == INT_MIN) {
            top->right = nullptr;
        } else {
            top->right = new TreeNode<T>(vv[j]);
            qu.push(top->right);
        }
        j++;
    }
    return root;
}

TreeNode<int> *lowestCommonAncestor(TreeNode<int> *root, TreeNode<int> *p,
                                    TreeNode<int> *q) {
    // 有一个是，就不向下找了；如果另一个也有，肯定是根，如果没有，就是当前子树
    if (!root || root == p || root == q) {
        return root;
    }

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    if (left && right) { // 左边也有，右边也有，返回根
        return root;
    }

    if (left) {
        return root->left;
    }
    return root->right; // 右子树和空合并返回结果，左边没有，右边也没有
}

// 并查集
// 查找 O(h)
// 合并 O(h)
struct UnionFind {
    vector<int> vv;
    UnionFind(int n) {
        vv.assign(n, 0);
        iota(vv.begin(), vv.end(), 0);
    }

    void unionTwo(int a, int b) {
        int fa = findX(a);
        int fb = findX(b);

        vv[fb] = fa;
    }

    int findX(int a) {
        if (vv[a] != a) {
            vv[a] = findX(vv[a]);
        }
        return vv[a];
    }

    int count() {
        int cnt = 0;
        for (int i = 0; i < vv.size(); i++) {
            if (vv[i] == i) {
                cnt++;
            }
        }
        return cnt;
    }

    bool isConnected(int a, int b) {
        int fa = findX(a);
        int fb = findX(b);

        return fa == fb;
    }
};

// 最小生成树
// 铺路, 连接所有城市，使铺设花费最少
// 1. Kruskal 按边贪心（用到并查集）
// 时间复杂度 O(eloge)
void Kruskal() {
    struct Edge {
        int x;
        int y;
        int len;
        Edge(int x, int y, int len) : x(x), y(y), len(len) {}
    };
    auto cmp = [](Edge &a, Edge &b) { return a.len < b.len; };

    vector<Edge> vv{{0, 1, 6}, {0, 2, 1}, {0, 3, 5}, {1, 2, 5}, {1, 4, 3},
                    {2, 3, 5}, {2, 4, 6}, {2, 5, 4}, {3, 5, 2}, {4, 5, 6}};

    sort(vv.begin(), vv.end(), cmp);
    UnionFind ud(6);

    // 每次获取最小的一条边
    // 如果已经连接过，就跳过
    int sum = 0;
    for (int i = 0; i < vv.size(); i++) {
        int x = vv[i].x;
        int y = vv[i].y;
        if (!ud.isConnected(x, y)) {
            ud.unionTwo(x, y);
            sum += vv[i].len;
        }
    }

    int cnt = ud.count();
    if (cnt == 1) {
        cout << "yes: " << sum << endl;
    } else {
        cout << "no" << endl;
    }
}

// 2. Prim 按点贪心
// 时间复杂度 O(n2)
void Prim() {
    int num = 6;
    vector<vector<int>> vv{{0, 1, 6}, {0, 2, 1}, {0, 3, 5}, {1, 2, 5},
                           {1, 4, 3}, {2, 3, 5}, {2, 4, 6}, {2, 5, 4},
                           {3, 5, 2}, {4, 5, 6}};
    vector<vector<pair<int, int>>> neibor(num);

    for (auto &edge : vv) {
        neibor[edge[0]].emplace_back(edge[1], edge[2]);
        neibor[edge[1]].emplace_back(edge[0], edge[2]);
    }

    vector<int> dist(num, INT_MAX); // 保存最小边

    queue<int> qu;
    unordered_set<int> uset;

    // init
    qu.push(0);
    dist[0] = 0;

    int sum = 0;

    while (!qu.empty()) {
        int t = qu.front();
        qu.pop();
        uset.insert(t);

        for (auto &edge : neibor[t]) {
            int node = edge.first;
            int val = edge.second;
            if (uset.find(node) != uset.end()) {
                continue;
            }

            if (val < dist[node]) {
                dist[node] = val;
            }
        }

        int min_pos = -1;
        int min_val = INT_MAX;
        for (int i = 0; i < num; i++) {
            if (uset.find(i) == uset.end()) {
                if (dist[i] < min_val) {
                    min_val = dist[i];
                    min_pos = i;
                }
            }
        }

        if (min_pos != -1) {
            sum += min_val;
            qu.push(min_pos);
        }
    }

    if (uset.size() == num) {
        cout << "yes: " << sum << endl;
    } else {
        cout << "no" << endl;
    }
}

void minimumTree() {
    Kruskal();
    Prim();
}

void testBuildTree() {
    vector<int> vv{1,       INT_MIN, 1, 1,       1,      INT_MIN,
                   INT_MIN, 1,       1, INT_MIN, 1,      INT_MIN,
                   INT_MIN, INT_MIN, 1, INT_MIN, INT_MIN};
    buildTree(vv);
}

// int main(void) {
// testBuildPreMidTree();
// UnionFind ud(10);
// minimumTree();

// return 0;
// }
