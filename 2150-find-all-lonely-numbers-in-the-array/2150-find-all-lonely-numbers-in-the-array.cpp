class Solution
{
public:
     vector<int> findLonely(vector<int> &nums)
     {
          vector<int> mark(1000001);
          for (auto &&num : nums)
               mark[num]++;
          vector<int> ans;
          for (int i = 0; i < nums.size(); i++)
               if (nums[i] == 0 and !(mark[nums[i] + 1] or mark[nums[i]] > 1))
                    ans.push_back(nums[i]);
               else if (nums[i] == 1000000 and !(mark[nums[i] - 1] or mark[nums[i]] > 1))
                    ans.push_back(nums[i]);
               else if ((nums[i] > 0 and nums[i] < 1000000) and !(mark[nums[i] - 1] or mark[nums[i]] > 1 or mark[nums[i] + 1]))
                    ans.push_back(nums[i]);
          return ans;
     }
};