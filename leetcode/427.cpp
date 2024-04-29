#include "../template/head.h"
#include <bits/stdc++.h>

class Node {
  public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
         Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
Node *construct(vector<vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();

    auto getVal = [&](int bi, int bj, int len) {
        int sum = 0;
        for (int i = bi; i < bi + len; i++) {
            for (int j = bj; j < bj + len; j++) {
                sum += grid[i][j];
            }
        }
        return sum;
    };

    function<Node *(int, int, int)> dfs = [&](int i, int j, int len) {
        // 不能直接传 node，如果孩子指针是空指针就没有办法 new
        int sub_len = len >> 1;
        int topLeft = getVal(i, j, sub_len),
            topRight = getVal(i, j + sub_len, sub_len);
        int bottomLeft = getVal(i + sub_len, j, sub_len),
            bottomRight = getVal(i + sub_len, j + sub_len, sub_len);

        Node *root;
        if (topLeft == topRight && topRight == bottomRight &&
            bottomRight == bottomLeft && bottomLeft == topLeft &&
            (topLeft == 0 || topLeft == sub_len * sub_len)) {
            root = new Node(grid[i][j], true);
        } else {
            root = new Node(true, false, dfs(i, j, sub_len),
                            dfs(i, j + sub_len, sub_len),
                            dfs(i + sub_len, j, sub_len),
                            dfs(i + sub_len, j + sub_len, sub_len));
        }
        return root;
    };

    return dfs(0, 0, n);
};

Node *construct_wrong(vector<vector<int>> grid) {

    int m = grid.size(), n = grid[0].size();

    auto getVal = [&](int bi, int bj, int len) {
        int sum = 0;
        for (int i = bi; i < bi + len; i++) {
            for (int j = bj; j < bj + len; j++) {
                sum += grid[i][j];
            }
        }
        return sum;
    };

    // 这种写法是错误的，root 的孩子节点是空指针，无法 new
    function<void(Node *, int, int, int)> dfs = [&](Node *root, int i, int j,
                                                    int len) {
        int sub_len = len >> 1;
        int val = pow(2, sub_len);
        int topLeft = getVal(i, j, sub_len),
            topRight = getVal(i, j + sub_len, sub_len);
        int bottomLeft = getVal(i + sub_len, j, sub_len),
            bottomRight = getVal(i + sub_len, j + sub_len, sub_len);

        if (topLeft == topRight && topRight == bottomRight &&
            bottomRight == bottomLeft && bottomLeft == topLeft) {
            root->val = grid[i][j];
            root->isLeaf = true;
        } else {
            // 这里 root->topLeft 是空指针, 没有留有指针地址
            root->topLeft = new Node();
            root->topRight = new Node();
            root->bottomLeft = new Node();
            root->bottomRight = new Node();
            dfs(root->topLeft, i, j, sub_len);
            dfs(root->topRight, i, j + sub_len, sub_len);
            dfs(root->bottomLeft, i + sub_len, j, sub_len);
            dfs(root->bottomRight, i + sub_len, j + sub_len, sub_len);
        }
    };

    Node *root = new Node();
    dfs(root, 0, 0, n);
    return root;
}

void printNode(Node *root) {
    cout << root->isLeaf << ", " << root->val << endl;
    if (root->isLeaf) {
        return;
    }

    printNode(root->topLeft);
    printNode(root->topRight);
    printNode(root->bottomLeft);
    printNode(root->bottomRight);
}

int main(int argc, char *argv[]) {
    // printNode(construct({{0, 1}, {1, 0}}));
    // printNode(construct({{1, 1, 1, 1, 0, 0, 0, 0},
    //                      {1, 1, 1, 1, 0, 0, 0, 0},
    //                      {1, 1, 1, 1, 1, 1, 1, 1},
    //                      {1, 1, 1, 1, 1, 1, 1, 1},
    //                      {1, 1, 1, 1, 0, 0, 0, 0},
    //                      {1, 1, 1, 1, 0, 0, 0, 0},
    //                      {1, 1, 1, 1, 0, 0, 0, 0},
    //                      {1, 1, 1, 1, 0, 0, 0, 0}}));
    printNode(
        construct({{1, 1, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}}));

    return 0;
}
