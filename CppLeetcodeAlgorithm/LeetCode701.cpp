#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
// 二叉搜索树中的插入操作
// 递归法
class Solution1 {
   public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};
// 迭代法
class Solution2 {
   public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* cur = root;
        TreeNode* parent = root;
        while (cur != NULL) {
            parent = cur;
            if (val > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
        TreeNode* node = new TreeNode(val);
        if (val > parent->val)
            parent->right = node;
        else
            parent->left = node;
        return root;
    }
};