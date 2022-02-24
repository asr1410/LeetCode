class Solution
{
public:
    int dfs(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;
        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);
        diameter = max(diameter, left + right);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
};