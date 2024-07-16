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
    bool traversal(TreeNode* one, TreeNode* two, bool &check) {
        if(check == false) {
            return false;
        } else if(one == nullptr and two == nullptr) {
            return true;
        } else if(one == nullptr and two != nullptr) {
            return check = false;
        } else if(one != nullptr and two == nullptr) {
            return check = false;
        } else if(one->val != two->val) {
            return check = false;
        } else {
            traversal(one->left, two->right, check);
            traversal(one->right, two->left, check);
        }
        return check;
    }
    bool isSymmetric(TreeNode* root) {
        bool check = true;
        traversal(root->left, root->right, check);
        return check;
    }
};