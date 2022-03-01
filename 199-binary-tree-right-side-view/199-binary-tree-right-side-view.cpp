class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        map<int, int> m;
        while (!q.empty())
        {
            auto len = q.size();
            for (auto i = 0; i < len; i++)
            {
                auto curr = q.front();
                q.pop();
                auto node = curr.first;
                auto row = curr.second;
                m[row] = node->val;
                if (node->left)
                    q.push(make_pair(node->left, row + 1));
                if (node->right)
                    q.push(make_pair(node->right, row + 1));
            }
        }
        for (auto &&it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};