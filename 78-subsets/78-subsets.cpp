class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets{{}};

        for(int num : nums)
        {
            int n = sets.size();
            for(int i = 0; i < n; i++)
            {
                sets.push_back(sets[i]);
                sets.back().push_back(num);
            }
        }
        return sets;
    }
};