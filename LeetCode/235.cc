//
// Created by shawn on 24-3-12.
//
#include <bits/stdc++.h>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *a = root;
        while ((q->val > a->val && p->val > a->val) || (q->val < a->val && p->val > a->val)) {
            if (p->val > a->val) {
                a = a->right;
            } else {
                a = a->left;
            }
        }
        return a;
    }
};