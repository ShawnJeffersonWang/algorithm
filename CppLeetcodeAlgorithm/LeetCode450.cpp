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
// 删除二叉搜索树中的节点
// 递归法
class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;
        if (root->val == key) {
            if (root->left == nullptr)
                return root->right;
            else if (root->right == nullptr)
                return root->left;
            else {
                TreeNode* cur = root->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        return root;
    }
};
// 迭代法