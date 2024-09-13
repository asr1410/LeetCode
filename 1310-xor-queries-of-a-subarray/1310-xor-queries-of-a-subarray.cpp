class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors{0};
        for(int i = 0; i < arr.size(); i++) {
            xors.emplace_back(xors[i] ^ arr[i]);
        }
        vector<int> ans;
        for(auto q : queries) {
            ans.push_back(xors[q[0]] ^ xors[q[1] + 1]);
        }
        return ans;
    }
};