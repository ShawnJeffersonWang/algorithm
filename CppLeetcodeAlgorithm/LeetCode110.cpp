
// Definition for a binary tree node.
#include <algorithm>
#include <cmath>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int getDepth(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int leftDepth = getDepth(node->left);
    if (leftDepth == -1) return -1;
    int rightDepth = getDepth(node->right);
    if (rightDepth == -1) return -1;
    return std::abs(leftDepth - rightDepth) > 1
               ? -1
               : 1 + std::max(leftDepth, rightDepth);
  }
  bool isBalanced(TreeNode *root) {
    return getDepth(root) == -1 ? false : true;
  }
};