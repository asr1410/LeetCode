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
    bool check = true;
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        } else if(check == true) {
            check = false;
            int left = diameterOfBinaryTree(root->left);
            int right = diameterOfBinaryTree(root->right);
            ans = max(ans, left + right);
            return ans;
        }
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};