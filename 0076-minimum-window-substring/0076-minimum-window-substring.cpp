class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umapt;
        unordered_map<char, int> umaps;
        int n = s.size(), k = t.size();
        pair<int, int> ans = {-1, n}; // Initialize ans with an invalid window
        
        // Populate umapt with frequency of characters in t
        for(int i = 0; i < k; i++) {
            umapt[t[i]]++;
        }
        
        // Two pointers approach
        for(int l = 0, r = 0, count = 0; r < n; r++) {
            // Expand the window by including s[r]
            if(umapt.find(s[r]) != umapt.end()) {
                umaps[s[r]]++;
                // Count only when the frequency of s[r] in the window matches or exceeds its requirement in umapt
                if(umaps[s[r]] <= umapt[s[r]]) {
                    count++;
                }
            }
            
            // Contract the window from the left if all characters of t are found in the current window
            while(count == k) {
                // Update ans if the current window is smaller than the previously recorded one
                if(r - l + 1 < ans.second - ans.first + 1) {
                    ans = {l, r};
                }
                
                // Remove s[l] from the window
                if(umapt.find(s[l]) != umapt.end()) {
                    umaps[s[l]]--;
                    // Update count only when the frequency of s[l] becomes less than required
                    if(umaps[s[l]] < umapt[s[l]]) {
                        count--;
                    }
                }
                
                // Move the left pointer to shrink the window
                l++;
            }
        }
        
        // If ans was not updated, return an empty string
        if(ans.first == -1) {
            return "";
        } else {
            return s.substr(ans.first, ans.second - ans.first + 1);
        }
    }
};