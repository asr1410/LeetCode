class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        auto ans = 0;
        while (!q.empty())
        {
            auto len = q.size();
            auto mn = q.front().second;
            int first , last;
            for (int i = 0; i < len; i++)
            {
                auto curr = q.front();
                q.pop();
                auto node = curr.first;
                auto idx = curr.second - mn;
                if (i == 0)
                    first = idx;
                if (i == len - 1)
                    last = idx;
                if (node->left)
                    q.push(make_pair(node->left, (long long)idx * 2 + 1));
                if (node->right)
                    q.push(make_pair(node->right, (long long)idx * 2 + 2));
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};