class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> uset;
      for(auto num : nums) {
        if(uset.find(num) != uset.end()) {
          return true;
        }
        uset.emplace(num);
      }
      return false;
    }
};