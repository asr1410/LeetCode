class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        int ans = 0, count = 0;
        TreeNode *cur;
        q.push(root);
        while (!q.empty())
        {
            ans++, count = q.size();
            while (count--)
            {
                cur = q.front();
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
                q.pop();
            }
        }
        return ans;
    }
};