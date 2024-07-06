class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umapt;
        unordered_map<char, int> umaps;
        int n = s.size(), k = t.size();
        pair<int, int> ans = {-1, n};
        for(int i = 0; i < k; i++) {
            umapt[t[i]]++;
        }
        for(int l = 0, r = 0, count = 0; r < n; r++) {
            if(umapt.find(s[r]) != umapt.end()) {
                umaps[s[r]]++;
                count += umaps[s[r]] <= umapt[s[r]];
            }
            while(count == k) {
                if(ans.second - ans.first + 1 > r - l + 1) {
                    ans = {l, r};
                }
                if(umapt.find(s[l]) != umapt.end()) {
                    umaps[s[l]]--;
                    count -= umaps[s[l]] < umapt[s[l]];
                }
                l++;
            }
        }
        if(ans.first == -1) {
            return "";
        } else {
            return s.substr(ans.first, ans.second - ans.first + 1);
        }
    }
};