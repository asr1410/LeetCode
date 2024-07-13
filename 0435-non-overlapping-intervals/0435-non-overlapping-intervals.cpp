class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        for(int i = 0; i < intervals.size(); i++) {
            minh.push(make_pair(intervals[i][1], intervals[i][0]));
        }
        int last = INT_MIN, count = 0;
        while(minh.empty() == false) {
            auto top = minh.top();
            minh.pop();
            if(top.second >= last) {
                count++;
                last = top.first;
            }
        }
        return intervals.size() - count;
    }
};