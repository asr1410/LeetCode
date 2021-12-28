class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans{{}};
        vector<vector<int>> an;
        vector<int>nums;
        for(int i=1; i<=n; i++)
        {
            nums.push_back(i);
        }
        for(int num : nums)
        {
            int n = ans.size();
            for(int i=0; i<n; i++)
            {
                ans.push_back(ans[i]);
                ans.back().push_back(num);
            }
        }
        for(int i = 0; i<ans.size(); i++)
        {
            if(ans[i].size() == k)
                an.push_back(ans[i]);
        }
        ans.clear();
        return an;
    }
};