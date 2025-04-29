class Solution {
public:
    vector<int> fen;
    int fen_n;

    void update(int idx, int val) {
        while (idx < fen_n) {
            fen[idx] += val;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += fen[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        fen.resize(n + 1, 0);
        fen_n = n + 1;
        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) > maxDiff) {
                update(i + 1, 1);
            }
        }

        vector<bool> ans;
        for (const auto& q : queries) {
            ans.push_back((query(q[1] + 1) - query(q[0] + 1)) == 0);
        }
        return ans;
    }
};
