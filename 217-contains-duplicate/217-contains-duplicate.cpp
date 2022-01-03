class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> arr;
     for (auto i : nums)
     {
          if (arr.find(i) != arr.end())
               return true;
          arr.emplace(i, true);
     }
     return false;
    }
};