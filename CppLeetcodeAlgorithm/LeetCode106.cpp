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
/*
// 从中序与后序遍历序列构造二叉树
class Solution1 {
   private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0)
            return NULL;
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);
        if (postorder.size() == 1)
            return root;
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size();
             delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue)
                break;
        }
        // 切割中序数组
        vector<int> leftInorder(inorder.begin(),
                                inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1,
                                 inorder.end());
        postorder.resize(postorder.size() - 1);
        // 切割后序数组
        vector<int> leftPostorder(postorder.begin(),
                                  postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(),
                                   postorder.end());
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return traversal(inorder, postorder);
    }
};*/
// 使用下标分割数组
class Solution2 {
   private:
    TreeNode* traversal(vector<int>& inorder,
                        int inorderBegin,
                        int inorderEnd,
                        vector<int>& postorder,
                        int postorderBegin,
                        int postorderEnd) {
        if (postorderBegin == postorderEnd)
            return NULL;
        int rootValue = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootValue);
        if (postorderEnd - postorderBegin == 1)
            return root;
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd;
             delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue)
                break;
        }
        // 切割中序数组
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;
        // 切割后序数组
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin;
        int rightPostorderBegin =
            postorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderEnd = postorderEnd - 1;
        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,
                               postorder, leftPostorderBegin, leftPostorderEnd);
        root->right =
            traversal(inorder, rightInorderBegin, rightInorderEnd, postorder,
                      rightPostorderBegin, rightPostorderEnd);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }
        return traversal(inorder, 0, postorder.size(), postorder, 0,
                         postorder.size());
    }
};

int main() {
    Solution2 s;
    vector<int> inorder = {8, 4, 15, 12, 7};
    vector<int> postorder = {8, 15, 7, 12, 4};
    s.buildTree(inorder, postorder);
    return 0;
}