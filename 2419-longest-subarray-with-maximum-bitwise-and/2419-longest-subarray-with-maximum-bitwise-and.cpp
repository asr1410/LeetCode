class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int count = 0, temp = 0;
        cout << count << endl;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == mx) {
                temp++;
            } else {
                ans = max(ans, temp);
                temp = 0;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};