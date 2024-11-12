class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        map<int, int> mp;
        int carry = 0;
        for(auto& item : items) {
            carry = max(carry, item[1]);
            mp[item[0]] = carry;
        }
        vector<int> ans;
        for(auto& q : queries) {
            auto it = mp.upper_bound(q);
            if(it == mp.begin()) {
                if(it->first > q) {
                    ans.push_back(0);
                } else {
                    ans.push_back(it->second);
                }
            } else if(it == mp.end()) {
                it--;
                ans.push_back(it->second);
            } else {
                if(it->first > q) {
                    it--;
                    ans.push_back(it->second);
                } else {
                    ans.push_back(it->second);
                }
            }
        }
        return ans;
    }
};