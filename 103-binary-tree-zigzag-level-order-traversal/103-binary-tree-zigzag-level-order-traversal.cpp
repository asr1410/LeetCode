class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        deque<TreeNode *> d;
        d.push_back(root);
        int i = 0;
        while (!d.empty())
        {
            int len = d.size();
            vector<int> sub;
            if (i % 2 == 0)
            {
                for (int i = 0; i < len; i++)
                {
                    auto temp = d.front();
                    d.pop_front();
                    if (temp->left)
                        d.push_back(temp->left);
                    if (temp->right)
                        d.push_back(temp->right);
                    sub.push_back(temp->val);
                }
            }
            else
            {
                for (int i = 0; i < len; i++)
                {
                    auto temp = d.back();
                    d.pop_back();
                    if (temp->right)
                        d.push_front(temp->right);
                    if (temp->left)
                        d.push_front(temp->left);
                    sub.push_back(temp->val);
                }
            }
            ans.push_back(sub);
            i++;
        }
        return ans;
    }
};