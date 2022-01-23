class Solution
{
public:
     vector<int> findLonely(vector<int> &nums)
     {
          vector<int> mark(1000001);
          for (auto &&num : nums)
               mark[num]++;
          vector<int> ans;
          for (auto &&num : nums)
               if (num == 0 and !(mark[num + 1] or mark[num] > 1))
                    ans.push_back(num);
               else if (num == 1000000 and !(mark[num - 1] or mark[num] > 1))
                    ans.push_back(num);
               else if ((num > 0 and num < 1000000) and !(mark[num - 1] or mark[num] > 1 or mark[num + 1]))
                    ans.push_back(num);
          return ans;
     }
};