/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* tmp;
        TreeNode* n = root;
        if (!root) return nullptr;
        if (n->left || n->right) {
            tmp = n->left;
            n->left = n->right;
            n->right = tmp;
            if (n->left) invertTree(n->left);
            if (n->right) invertTree(n->right);
        }
        return root;
    }
};
