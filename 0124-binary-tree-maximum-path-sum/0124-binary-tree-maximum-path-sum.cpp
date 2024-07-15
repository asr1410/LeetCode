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
        if(root == nullptr) {
            return 0;
        }
        int left = pathsum(root->left, ans);
        int right = pathsum(root->right, ans);
        int curr = max({left + root->val, right + root->val, root->val});
        ans = max({ans, curr, root->val + left + right});
        return curr;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        pathsum(root, ans);
        return ans;
    }
};