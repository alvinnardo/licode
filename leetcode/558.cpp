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

Node *copyFromNode(Node *quadTree) {
    return new Node(quadTree->val, quadTree->isLeaf, quadTree->topLeft,
                    quadTree->topRight, quadTree->bottomLeft,
                    quadTree->bottomRight);
}
Node *intersect(Node *quadTree1, Node *quadTree2) {
    // 思路：DFS
    // 因为是或运算，如果一个叶子矩阵中都是 1，那么后面全是 1
    // 如果一个叶子矩阵中都是 0，那么后面肯定都是对方矩阵
    if (quadTree1->isLeaf) {
        if (quadTree1->val == 1) {
            return copyFromNode(quadTree1);
        } else {
            return copyFromNode(quadTree2);
        }
    } else if (quadTree2->isLeaf) {
        if (quadTree2->val == 1) {
            return copyFromNode(quadTree2);
        } else {
            return copyFromNode(quadTree1);
        }
    }

    Node *topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
    Node *topRight = intersect(quadTree1->topRight, quadTree2->topRight);
    Node *bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
    Node *bottomRight =
        intersect(quadTree1->bottomRight, quadTree2->bottomRight);

    // 或运算后结果相同了
    if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf &&
        bottomRight->isLeaf) {
        if (topLeft->val == 1 && topRight->val == 1 && bottomLeft->val == 1 &&
            bottomRight->val == 1) {
            return new Node(1, 1);
        } else if (topLeft->val == 0 && topRight->val == 0 &&
                   bottomLeft->val == 0 && bottomRight->val == 0) {
            return new Node(1, 0);
        }
    }

    Node *root = new Node(0, 0, topLeft, topRight, bottomLeft, bottomRight);
    return root;
}

int main(int argc, char *argv[]) { return 0; }
