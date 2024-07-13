class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1]; 
        });
        int last = INT_MIN, count = 0;
        for(int i = 0; i < intervals.size(); i++) {
            if(last <= intervals[i][0]) {
                last = intervals[i][1];
            } else {
                count++;
            }
        }
        return count;
    }
};