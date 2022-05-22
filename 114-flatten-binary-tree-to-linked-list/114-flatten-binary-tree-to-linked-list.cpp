class Solution
{
public:
    void flatten(TreeNode *root)
    {
        auto curr = root;
        while (curr)
        {
            if (curr->left)
            {
                auto prev = curr->left;
                while (prev->right)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};