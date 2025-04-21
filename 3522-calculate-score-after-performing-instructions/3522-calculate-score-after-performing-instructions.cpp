class Solution {
public:
    long long calculateScore(vector<string>& ins, vector<int>& val) {
        int n = val.size(), i = 0;
        long long ans = 0;
        vector<int> mark(n, 0);
        while(i >= 0 and i < n and mark[i] == 0) {
            mark[i] = 1;
            if(ins[i] == "jump") {
                i += val[i];
            } else {
                ans += val[i];
                i++;
            }
        }
        return ans;
    }
};