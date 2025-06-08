class Solution {
public:
    vector<int> ans;

    void helper(int k, int n) {
        if (k > n) return;
        ans.push_back(k);
        for (int i = 0; i <= 9; i++) {
            int next = k * 10 + i;
            helper(next, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            if (i > n) break;
            helper(i, n);
        }
        return ans;
    }
};
