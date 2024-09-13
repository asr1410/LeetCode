class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xors(n + 1, 0);
        for(int i = 0, j = 1; i < n; j++, i++) {
            xors[j] = xors[i] ^ arr[i];
        }
        vector<int> ans;
        for(auto q : queries) {
            ans.push_back(xors[q[0]] ^ xors[q[1] + 1]);
        }
        return ans;
    }
};