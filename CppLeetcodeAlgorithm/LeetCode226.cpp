#include <bits/stdc++.h>
using namespace std;
// 翻转二叉树
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// 递归法
class Solution1 {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// 迭代法模拟前序遍历
class Solution2 {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return root;
    }
};

// 层序遍历
class Solution3 {
   public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr)
            que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left,
                     node->right);  // 真正的处理逻辑,入队的顺序是反转过的
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return root;
    }
};