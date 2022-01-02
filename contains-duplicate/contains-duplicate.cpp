class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> M;
        for(auto &&s: nums)
        {
            if (M.find(s) == M.end())
                M.insert(make_pair(s, 1));
            else
                return true;
        }
        return false;
    }
};