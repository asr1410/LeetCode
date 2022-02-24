class Solution
{
public:
    int dfs(TreeNode *root, int &sum)
    {
        if (!root)
            return 0;
        int lsum = max(0, dfs(root->left, sum));
        int rsum = max(0, dfs(root->right, sum));
        sum = max(sum, root->val + lsum + rsum);
        return root->val + max(lsum, rsum);
    }
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }
};