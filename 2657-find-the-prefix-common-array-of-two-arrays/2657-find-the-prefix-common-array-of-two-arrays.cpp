class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> sa, sb;
        vector<int> ans;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            sa.insert(A[i]);
            sb.insert(B[i]);
            auto first = sa.begin(), second = sb.begin();
            int count = 0;
            while(first != sa.end() and second != sb.end()) {
                if(*first < *second) {
                    first++;
                } else if(*first > *second) {
                    second++;
                } else {
                    count++;
                    first++;
                    second++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
