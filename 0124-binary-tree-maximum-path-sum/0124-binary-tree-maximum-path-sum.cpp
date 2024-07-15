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
    int pathsum(TreeNode* root, int &ans) {
        if(root->left == nullptr and root->right == nullptr) {
            ans = max(ans, root->val);
            return root->val;
        } else if(root->right == nullptr) {
            int left = pathsum(root->left, ans);
            ans = max(ans, max(left, max(root->val + left, root->val)));
            return max(root->val, root->val + left);
        } else if(root->left == nullptr) {
            int right = pathsum(root->right, ans);
            ans = max(ans, max(right, max(root->val + right, root->val)));
            return max(root->val, root->val + right);
        }
        int left = pathsum(root->left, ans);
        int right = pathsum(root->right, ans);
        ans = max(ans, max(root->val, max(left + right + root->val, max(left + root->val, right + root->val))));
        return max(root->val, max(left + root->val, right + root->val));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        pathsum(root, ans);
        return ans;
    }
};