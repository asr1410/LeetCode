class Solution
{
    map<int, map<int, multiset<int>>> mymap;
    void solve(TreeNode *curr, int col, int row)
    {
        if (!curr)
            return;
        mymap[col][row].insert(curr->val);
        solve(curr->left, col - 1, row + 1);
        solve(curr->right, col + 1, row + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        solve(root, 0, 0);
        vector<vector<int>> ans;
        for (auto m1 : mymap)
        {
            vector<int>temp;
            for (auto m2 : m1.second)
                for (auto m3 : m2.second)
                    temp.push_back(m3);
            ans.push_back(temp);
        }
        return ans;
    }
};