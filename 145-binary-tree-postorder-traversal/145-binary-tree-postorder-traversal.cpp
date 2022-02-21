class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> ans;
        while (!s.empty() or root)
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                auto temp = s.top()->right;
                if (!temp)
                {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while (!s.empty() && s.top()->right == temp)
                    {
                        temp = s.top(), s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    root = temp;
                }
            }
        }
        return ans;
    }
};