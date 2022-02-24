class Solution
{
public:
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        int lh = depth(root->left);
        int rh = depth(root->right);
        return abs(lh - rh) <= 1 and isBalanced(root->left) and isBalanced(root->right);
    }
};