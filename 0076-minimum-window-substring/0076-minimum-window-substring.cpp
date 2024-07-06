class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umapt;
        unordered_map<char, int> umaps;
        int n = s.size(), k = t.size();
        pair<int, int> ans = {-1, n};
        
        for (char c : t) {
            umapt[c]++;
        }
        
        for (int l = 0, r = 0, count = 0; r < n; r++) {
            if (umapt.find(s[r]) != umapt.end()) {
                umaps[s[r]]++;
                if (umaps[s[r]] <= umapt[s[r]]) {
                    count++;
                }
            }
            
            while (count == k) {
                if (r - l < ans.second - ans.first) {
                    ans = {l, r};
                }
                
                if (umapt.find(s[l]) != umapt.end()) {
                    umaps[s[l]]--;
                    if (umaps[s[l]] < umapt[s[l]]) {
                        count--;
                    }
                }
                
                l++;
            }
        }
        
        if (ans.first == -1) {
            return "";
        } else {
            return s.substr(ans.first, ans.second - ans.first + 1);
        }
    }
};
