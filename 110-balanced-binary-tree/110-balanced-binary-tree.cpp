class Solution
{
public:
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = depth(root->left);
        if (lh == -1)
            return -1;
        int rh = depth(root->right);
        if (rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return depth(root) != -1;
    }
};