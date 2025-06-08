class Solution {
public:
    vector<int> ans;
    void helper(int k, int n) {
        if(k > n) {
            return;
        }
        ans.push_back(k);
        for(int i = 0; i <= 9; i++) {
            helper(k * 10 + i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++) {
            helper(i, n);
        }
        return ans;
    }
};