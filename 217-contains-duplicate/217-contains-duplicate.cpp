class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>arr;
        for(auto i : nums)
        {
            if(arr.find(i)!=arr.end())
                return true;
            arr.insert(i);
        }
        return false;
    }
};