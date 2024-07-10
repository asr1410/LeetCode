class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (int num : nums) {
            umap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        for (auto it : umap) {
            minh.emplace(it.second, it.first);
            if (minh.size() > k) {
                minh.pop();
            }
        }
        vector<int> result;
        while (!minh.empty()) {
            result.push_back(minh.top().second);
            minh.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};
