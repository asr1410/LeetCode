class Solution {
public:
    bool diff(string& s1, string& s2) {
        int ans = 0;
        string t1, t2;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) {
                ans++;
                t1.push_back(s1[i]);
                t2.push_back(s2[i]);
            }
        }
        return ans == 2 and t1[0] == t2[1] and t1[1] == t2[0];
    }
    int countPairs(vector<int>& nums) {
        vector<string> snums;
        int len = 0;
        for(int i = 0; i < nums.size(); i++) {
            len = max(len, (int)to_string(nums[i]).size());
        }
        for(int i = 0; i < nums.size(); i++) {
            string sh = to_string(nums[i]);
            int rem = len - sh.size();
            string fh = string(rem, '0');
            snums.push_back(fh + sh);
        }
        int ans = 0;
        for(int i = 0; i < snums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(snums[i] == snums[j] or diff(snums[i], snums[j]) == true) {
                    ans++;
                }
            }
        }
        return ans;
    }
};