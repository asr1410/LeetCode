class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> umap;
        for(const int& answer : answers) {
            umap[answer]++;
        }
        int ans = 0;
        for(const auto& it : umap) {
            int pairs = ceil((it.second * 1.0f) / (it.first + 1.0f));
            ans += pairs * (it.first + 1);
        }
        return ans;
    }
};