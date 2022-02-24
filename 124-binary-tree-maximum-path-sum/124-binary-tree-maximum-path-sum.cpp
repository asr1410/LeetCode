
class Solution
{
public:
    int dfs(TreeNode *root, int &sum)
    {
        if (!root)
            return 0;
        int leftsum = max(0, dfs(root->left, sum));
        int rightsum = max(0, dfs(root->right, sum));
        sum = max(sum, root->val + leftsum + rightsum);
        return root->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }
};