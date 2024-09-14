class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        priority_queue <int, vector<int>, greater<int>> pq;
        sort(A.begin(), A.end());
        int i = 0, res = 0, d = 0, n = A.size();
        while (pq.size() > 0 || i < n) {
            if (pq.size() == 0)
                d = A[i][0];
            while (i < n && A[i][0] <= d)
                pq.push(A[i++][1]);
            pq.pop();
            ++res, ++d;
            while (pq.size() > 0 && pq.top() < d)
                pq.pop();

        }
        return res;
    }
};