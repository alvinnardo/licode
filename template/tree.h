#pragma once
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

template <class T> vector<T> preEnumTree(TreeNode<T> *root);
template <class T> vector<T> midEnumTree(TreeNode<T> *root);
template <class T> vector<T> tailEnumTree(TreeNode<T> *root);

template <class T>
TreeNode<T> *buildPreMidTree(const vector<T> &pre_nums,
                             const vector<T> &mid_nums, int pre_left,
                             int pre_right, int mid_left, int mid_right);
template <class T> TreeNode<T> *buildTree(const vector<T> &vv);
