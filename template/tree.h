#pragma once
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

vector<int> preEnumTree(TreeNode *root);
vector<int> midEnumTree(TreeNode *root);
vector<int> tailEnumTree(TreeNode *root);
vector<int> levelEnumTree(TreeNode *root);

TreeNode *buildPreMidTree(const vector<int> &pre_nums,
                          const vector<int> &mid_nums, int pre_left,
                          int pre_right, int mid_left, int mid_right);
TreeNode *buildTree(vector<int> vv);
