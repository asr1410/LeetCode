class Solution {
public:
    vector<int> ans, temp, mark;
    
    bool helper(int m, int n, int index) {
        if (index == n) {
            ans = temp;
            return true;
        }
        if (temp[index] != 0) {
            return helper(m, n, index + 1);
        }
        for (int i = m; i >= 1; i--) {
            if (mark[i] == 0) {
                if (i == 1) {
                    temp[index] = 1;
                    mark[i] = 1;
                    if (helper(m, n, index + 1)) return true;
                    temp[index] = 0;
                    mark[i] = 0;
                } else if (index + i < n && temp[index + i] == 0) {
                    temp[index] = temp[index + i] = i;
                    mark[i] = 1;
                    if (helper(m, n, index + 1)) return true;
                    temp[index] = temp[index + i] = 0;
                    mark[i] = 0;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int m) {
        int n = 2 * m - 1;
        ans.resize(n, 0);
        temp.resize(n, 0);
        mark.resize(m + 1, 0);
        helper(m, n, 0);
        return ans;
    }
};
