class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> sa, sb;
        sa.push(root);
        while (!sa.empty())
        {
            root = sa.top();
            sa.pop();
            sb.push(root);
            if (root->left)
                sa.push(root->left);
            if (root->right)
                sa.push(root->right);
        }
        while (!sb.empty())
        {
            ans.push_back(sb.top()->val);
            sb.pop();
        }
        return ans;
    }
};