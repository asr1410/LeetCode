class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        TreeNode *curr;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        vector<vector<int>> ans;
        map<int, vector<int>> mymap;

        // BFS
        while (!q.empty())
        {
            int size = q.size();
            map<int, multiset<int>> mapset;
            while (size--)
            {
                curr = q.front().first;
                int col = q.front().second;
                q.pop();
                mapset[col].insert(curr->val);
                if (curr->left)
                    q.push({curr->left, col - 1});
                if (curr->right)
                    q.push({curr->right, col + 1});
            }
            for (auto it : mapset)
                for (auto it2 : it.second)
                    mymap[it.first].push_back(it2);
        }
        for (auto it : mymap)
            ans.push_back(it.second);
        return ans;
    }
};