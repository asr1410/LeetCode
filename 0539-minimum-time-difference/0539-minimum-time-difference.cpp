class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int n = timePoints.size();
        
        for (const auto& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }
        
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        minDiff = min(minDiff, (24 * 60 - minutes.back() + minutes.front()));
        
        return minDiff;
    }
};
