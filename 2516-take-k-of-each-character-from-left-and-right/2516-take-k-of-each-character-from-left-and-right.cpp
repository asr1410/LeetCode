class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        if (k == 0) return 0;
        
        vector<int> count(3, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        if (count[0] < k || count[1] < k || count[2] < k) {
            return -1;
        }
        
        vector<int> curr(3, 0);
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            curr[s[right] - 'a']++;
            
            while (left <= right && 
                   curr[0] > count[0] - k || 
                   curr[1] > count[1] - k || 
                   curr[2] > count[2] - k) {
                curr[s[left] - 'a']--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return n - maxLen;
    }
};