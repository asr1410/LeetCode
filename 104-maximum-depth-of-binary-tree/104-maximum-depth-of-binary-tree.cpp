class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            ans++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;
    }
};