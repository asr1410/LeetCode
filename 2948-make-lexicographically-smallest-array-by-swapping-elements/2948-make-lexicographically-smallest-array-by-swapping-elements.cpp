class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < n; i++) {
            indexed_nums.push_back({nums[i], i});
        }
        
        sort(indexed_nums.begin(), indexed_nums.end());
        
        vector<vector<int>> groups;
        vector<int> current_group;
        
        for (int i = 0; i < n; i++) {
            if (current_group.empty() || 
                indexed_nums[i].first - indexed_nums[current_group.back()].first <= limit) {
                current_group.push_back(i);
            } else {
                groups.push_back(current_group);
                current_group = {i};
            }
        }
        
        if (!current_group.empty()) {
            groups.push_back(current_group);
        }
        
        vector<int> result(n);
        for (auto& group : groups) {
            vector<int> values, indices;
            for (int idx : group) {
                values.push_back(indexed_nums[idx].first);
                indices.push_back(indexed_nums[idx].second);
            }
            
            sort(indices.begin(), indices.end());
            
            for (int i = 0; i < group.size(); i++) {
                result[indices[i]] = values[i];
            }
        }
        
        return result;
    }
};