class Solution {
public:
    unordered_set<long long> ans;
    int cnt[26] = {0};
    void helper(int i, long long curr) {
        ans.insert(curr);
        if(i == 0) {
            return;
        }
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > 0) {
                cnt[j]--;
                long long newVal = curr | ((long long)(j + 1) << (8 * i));
                helper(i - 1, newVal);
                cnt[j]++;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        for (char c : tiles) {
            cnt[c - 'A']++;
        }
        
        helper(tiles.size(), 0LL);
        return ans.size() - 1;
    }
};