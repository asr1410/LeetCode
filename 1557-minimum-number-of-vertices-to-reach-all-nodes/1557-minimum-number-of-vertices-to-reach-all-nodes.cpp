class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> uset;
        for(auto& edge : edges) {
            uset.emplace(edge[1]);
        }
        
        unordered_set<int> ans;
        for(auto& edge : edges) {
            if(uset.find(edge[0]) == uset.end()) {
                ans.emplace(edge[0]);
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};