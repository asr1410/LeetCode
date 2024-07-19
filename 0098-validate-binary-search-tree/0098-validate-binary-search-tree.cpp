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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return traverse(root, prev);
    }
    bool traverse(TreeNode* root, TreeNode* &prev) {
        if(root == nullptr) {
            return true;
        }
        if(traverse(root->left, prev) == false) {
            return false;
        }
        if(prev != nullptr and prev->val >= root->val) {
            return false;
        }
        prev = root;
        return traverse(root->right, prev);
    }
};