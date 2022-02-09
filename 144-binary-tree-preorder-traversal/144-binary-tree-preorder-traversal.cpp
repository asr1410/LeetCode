class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            if (root->right)
                s.push(root->right);
            if (root->left)
                s.push(root->left);
            ans.push_back(root->val);
        }
        return ans;
    }
};