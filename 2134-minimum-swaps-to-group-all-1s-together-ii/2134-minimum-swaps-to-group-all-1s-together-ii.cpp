class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int N = n * 2;
        int ocount = count(nums.begin(), nums.end(), 1);
        int ccount = 0;
        int ans = 0;
        for(int i = 0, j = 0; i < N; i++) {
            ccount += nums[i % n];
            ccount -= (i >= ocount and nums[j % n]);
            j += (i >= ocount);
            ans = max(ans, ccount);
        }
        cout << ocount << " " << ccount << endl;
        return ocount - ans;
    }
};