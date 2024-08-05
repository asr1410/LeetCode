class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> umap;
        for(auto& a:arr) {
            umap[a]++;
        }
        int count = 0;
        for(auto& a:arr) {
            count += umap[a] == 1;
            if(count == k) {
                return a;
            }
        }
        return "";
    }
};