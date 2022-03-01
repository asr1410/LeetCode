class Solution
{
public:
    bool help(TreeNode *left, TreeNode *right)
    {
        if (!left or !right)
            return left == right;
        if (left->val != right->val)
            return false;
        return help(left->left, right->right) and help(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return root == NULL or help(root->left, root->right);
    }
};