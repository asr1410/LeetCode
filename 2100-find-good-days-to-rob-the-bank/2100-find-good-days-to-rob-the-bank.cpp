class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int t) {
        int n = s.size();
        vector<int> pre(n, 1), pos(n, 1);
        for(int i = 1; i < n; i++) {
            if(s[i - 1] >= s[i]) {
                pre[i] += pre[i - 1];
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] <= s[i + 1]) {
                pos[i] += pos[i + 1];
            }
        }
        vector<int> ans;
        for(int i = t; i < n - t; i++) {
            if(pre[i] > t and pos[i] > t) {
                ans.push_back(i);
            }
        }
        // for(auto a : pre) {
        //     cout << a << " ";
        // }
        // cout << endl;
        // for(auto a : pos) {
        //     cout << a << " ";
        // }
        // cout << endl;
        return ans;
    }
};