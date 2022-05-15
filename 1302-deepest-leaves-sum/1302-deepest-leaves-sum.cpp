class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            ans = 0;
            int len = size(q);
            for (int i = 0; i < len; i++)
            {
                auto top = q.front();
                q.pop();
                ans += top->val;
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
        }
        return ans;
    }
};