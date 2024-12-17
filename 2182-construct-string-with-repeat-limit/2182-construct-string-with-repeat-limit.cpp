class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        vector<int> cnt(26, 0);
        for(char c : s)
            cnt[c - 'a']++;
        
        string ans;
        int idx = 25;
        bool flag = false;
        while(idx >= 0) {
            if(cnt[idx] > rl) {
                if(flag == true) {
                    idx--;
                    continue;
                }
                flag = true;
                ans += string(rl, 'a' + idx);
                cnt[idx] -= rl;
                for(int j = idx - 1; j >= 0; j--) {
                    if(cnt[j]) {
                        cnt[j]--;
                        ans.push_back('a' + j);
                        flag = false;
                        break;
                    }
                }
            } else {
                if(flag == true) {
                    idx--;
                    continue;
                }
                ans += string(min(rl, cnt[idx]), 'a' + idx);
                idx--;
            }
        }
        return ans;
    }
};