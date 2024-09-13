class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors;
        xors.push_back(0);
        for(int i = 0; i < arr.size(); i++) {
            xors.push_back(xors[i] ^ arr[i]);
        }
        vector<int> ans;
        for(auto q : queries) {
            ans.push_back(xors[q[0]] ^ xors[q[1] + 1]);
        }
        return ans;
    }
};