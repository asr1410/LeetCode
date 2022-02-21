class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            auto *curr = s.top();
            ans.push_back(s.top()->val);
            s.pop();
            if (curr->right)
                s.push(curr->right);
            if (curr->left)
                s.push(curr->left);
        }
        return ans;
    }
};