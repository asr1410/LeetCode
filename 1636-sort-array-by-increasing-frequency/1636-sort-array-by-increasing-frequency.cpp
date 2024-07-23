class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> freq(201);
        for(int i = 0; i < n; i++) {
            freq[nums[i] + 100].first = nums[i];
            freq[nums[i] + 100].second++;
        }
        sort(freq.begin(), freq.end(), [](const pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second or (a.second == b.second and a.first > b.first);
        });
        vector<int> ans;
        ans.resize(n);
        for(int i = 200; i >= 0 and freq[i].second > 0; i--) {
            for(int j = freq[i].second; j > 0; j--) {
                ans[--n] = freq[i].first;
            }
        }
        return ans;
    }
};