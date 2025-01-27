class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> vpi;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vpi.emplace_back(nums[i], i);
        }
        sort(vpi.begin(), vpi.end());
        vector<vector<pair<int, int>>> vvpi = {{vpi[0]}};
        for(int i = 1; i < n; i++) {
            if(vpi[i].first - vpi[i - 1].first <= limit) {
                vvpi.back().emplace_back(vpi[i]);
            } else {
                vvpi.push_back({vpi[i]});
            }
        }

        for(auto& vpi : vvpi) {
            vector<int> idx;
            for(auto& pi : vpi) {
                idx.emplace_back(pi.second);
            }
            sort(idx.begin(), idx.end());
            for(int i = 0; i < idx.size(); i++) {
                nums[idx[i]] = vpi[i].first;
            }
        }
        return nums;
    }
};