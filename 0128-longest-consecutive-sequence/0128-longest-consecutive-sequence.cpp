class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(const int& num : nums) {
            uset.emplace(num);
        }
        int ans = 0;
        unordered_map<int, int> umap;
        for(const int& num : nums) {
            if(uset.find(num) != uset.end()) {
                int count = 1, temp = num + 1;
                uset.erase(num);
                while(uset.find(temp) != uset.end()) {
                    count++;
                    uset.erase(temp);
                    temp++;
                }
                umap[num] = count + umap[temp];
                ans = max(ans, umap[num]);
            }
        }
        return ans;
    }
};
