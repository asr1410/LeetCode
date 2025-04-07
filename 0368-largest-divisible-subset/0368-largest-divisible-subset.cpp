class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // sort(begin(nums), end(nums));
        vector<int> ans;
        for(int i = 0; i < size(nums); i++) {         // any element is valid choice for 1st subset member
            auto res = solve(nums, i);                // try for each & obtain largest subset when nums[i] is starting element
            if(size(res) > size(ans)) ans = res;      // keep track of largest subset found
        }
        return ans;
    }
    vector<int> solve(vector<int>& nums, int start) {
        if(start >= size(nums)) return {};                      // no subset possible when start >= size(nums)
        vector<int> ans;
        for(int next = start+1; next < size(nums); next++) {    // try next elements 
            if(nums[next] % nums[start]) continue;              // only those completely divided by nums[start] are valid choice
            auto res = solve(nums, next);                       // res = largest subset on choosing nums[next]
            if(size(res) >= size(ans)) ans = res;               // ans = largest subset till now when nums[start] is previous element
        }
        ans.push_back(nums[start]);                             // we didnt include nums[start] in ans. Add it as well
        return ans;                                             // return largest subset starting with num[start]
    }
};