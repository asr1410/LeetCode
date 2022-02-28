class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        map<int, vector<int>> m;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            int len = q.size();
            map<int, multiset<int>> t;
            for (int i = 0; i < len; i++)
            {
                int col = q.front().second;
                t[col].insert(q.front().first->val);
                if (q.front().first->left)
                    q.push(make_pair(q.front().first->left, col - 1));
                if (q.front().first->right)
                    q.push(make_pair(q.front().first->right, col + 1));
                q.pop();
            }
            for (auto &&it : t)
            {
                for (auto &&it2 : it.second)
                {
                    m[it.first].push_back(it2);
                }
            }
        }
        for (auto &&it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};