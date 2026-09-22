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
    TreeNode* temp = nullptr;

public:
    void flatten(TreeNode* root) {
        helper(root);
    }

    void helper(TreeNode* root) {
        if (root == nullptr)
            return;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (temp != nullptr) {
            temp->right = root;
        }

        root->left = nullptr;
        temp = root;

        helper(left);
        helper(right);
    }
};
