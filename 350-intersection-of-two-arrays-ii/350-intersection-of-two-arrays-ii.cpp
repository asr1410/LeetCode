class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
     vector<int> ans;
     unordered_map<int, int> track;
     for (auto &&num : nums1)
     {
          track[num]++;
     }
     for (auto &&num : nums2)
     {
          auto it = track.find(num);
          if (it != track.end() && it->second > 0)
          {
               ans.push_back(num);
               track[num]--;
          }
     }
     return ans;
}
};