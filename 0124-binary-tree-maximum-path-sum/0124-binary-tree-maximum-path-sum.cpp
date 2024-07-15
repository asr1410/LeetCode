class Solution {
public:
    int pathsum(TreeNode* root, int &ans) {
        if (!root) return 0;
        int left = pathsum(root->left, ans);
        int right = pathsum(root->right, ans);
        int currentMax = max({root->val, root->val + left, root->val + right});
        ans = max(ans, max({currentMax, left + right + root->val}));

        return currentMax;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        pathsum(root, ans);
        return ans;
    }
};