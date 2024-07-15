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
    int depth(TreeNode* root, bool &check) {
        if(check == false) {
            return 0;
        }
        if(root == nullptr) {
            return 0;
        }
        int left = 1 + depth(root->left, check);
        int right = 1 + depth(root->right, check);
        if(check == true and abs(left - right) > 1) {
            check = false;
        }
        return max(left , right);
    }
    bool isBalanced(TreeNode* root) {
        bool check = true;
        depth(root, check);
        return check;
    }
};