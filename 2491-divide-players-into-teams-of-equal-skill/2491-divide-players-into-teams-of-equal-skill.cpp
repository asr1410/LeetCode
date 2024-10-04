class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long tsum = accumulate(skill.begin(), skill.end(), 0LL);
        int n = skill.size() / 2;
        int value = tsum / n;
        unordered_map<int, int> umap;
        int count = 0;
        long long ans = 0;
        for(int s : skill) {
            int rem = value - s;
            if(umap[rem] > 0) {
                umap[rem]--;
                ans = ans + s * rem;
                count++;
            } else {
                umap[s]++;
            }
        }
        return count == skill.size() / 2 ? ans : -1;
    }
};