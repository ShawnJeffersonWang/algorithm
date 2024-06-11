#include <vector>
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
// 验证二叉搜索树
// 递归法
class Solution {
   private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root == NULL)
            return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }

   public:
    bool isValidBST(TreeNode* root) {
        vec.clear();
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] <= vec[i - 1])
                return false;
        }
        return true;
    }
};