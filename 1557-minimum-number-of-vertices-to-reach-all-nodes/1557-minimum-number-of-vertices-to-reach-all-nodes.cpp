class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> count(n, 0);
        for(auto& edge : edges) {
            count[edge[1]] = 1;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(count[i] == 0) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};