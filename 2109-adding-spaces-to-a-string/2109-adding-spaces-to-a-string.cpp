class Solution {
public:
    string addSpaces(string s, vector<int>& A) {
        string ans;
        ans.reserve(s.size() + A.size()); // Optional: pre-allocate enough space for the answer.
        int N = s.size(), j = 0, M = A.size(); // `A[j]` is the next index before which a space should be inserted
        for (int i = 0; i < N; ++i) {
            if (j < M && i == A[j]) { // If `i == A[j]`, we insert a space
                ans += ' ';
                ++j;
            }
            ans += s[i];
        }
        return ans;
    }
};