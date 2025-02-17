class Solution {
public:
    unordered_set<long long> ans;
    
    void helper(int i, long long curr, vector<int>& cnt) {
        if (curr != 0) {
            ans.insert(curr);
        }
        if (i >= 7) return;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > 0) {
                cnt[j]--;
                long long newVal = curr | ((long long)(j + 1) << (8 * i));
                helper(i + 1, newVal, cnt);
                cnt[j]++;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26, 0);
        for (char c : tiles) {
            cnt[c - 'A']++;
        }
        
        helper(0, 0LL, cnt);
        return ans.size();
    }
};