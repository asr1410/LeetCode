class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> umap;
        for(int i = 1, val, temp; i <= n; i++) {
            val = i;
            temp = 0;
            while(val) {
                temp += val % 10;
                val /= 10;
            }
            umap[temp]++;
        }
        int mx = 0;
        for(const auto& it : umap) {
            mx = max(mx, it.second);
        }
        int ans = 0;
        for(const auto& it : umap) {
            ans += mx == it.second;
        }
        return ans;
    }
};