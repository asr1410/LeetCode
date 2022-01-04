class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
     unordered_map<int, int> track;
     for (auto &&num : nums1)
          track[num]++;
     for (auto &&num : nums2)
          if (track[num]-- > 0)
               ans.push_back(num);
     return ans;
    }
};