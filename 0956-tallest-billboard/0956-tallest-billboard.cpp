class Solution {
public:
    int dfs(vector<int>& rs, int i, int s1, int s2, int m_sum, vector<vector<int>> &m) {
        if (s1 > m_sum || s2 > m_sum) return -1;
        if (i >= rs.size()) return s1 == s2 ? s1 : -1;
        if (m[i][abs(s1 - s2)] == -2) {
            m[i][abs(s1 - s2)] = max(-1, max({dfs(rs, i + 1, s1, s2, m_sum, m), dfs(rs, i + 1, s1 + rs[i], s2, m_sum, m), dfs(rs, i + 1, s1, s2 + rs[i], m_sum, m)}) - max(s1, s2));
        }
        return m[i][abs(s1 - s2)] + (m[i][abs(s1 - s2)] == -1 ? 0 : max(s1, s2));
    }

    int tallestBillboard(vector<int>& rods) {
        int m_sum = accumulate(begin(rods), end(rods), 0) / 2;
        vector<vector<int>> m(rods.size(), vector<int>(m_sum + 1, -2));
        return max(0, dfs(rods, 0, 0, 0, m_sum, m));
    }
};
