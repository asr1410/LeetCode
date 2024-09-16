class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int> ntp;
        int minutes = 24 * 60, n = tp.size(), ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int min = 0;
            stringstream ss(tp[i]);
            string s;
            char sep = ':';
            bool hour = true;
            while(getline(ss, s, sep)) {
                if(hour) {
                    min += stoi(s) * 60;
                    hour = false;
                } else {
                    min += stoi(s);
                }
            }
            ntp.push_back(min);
        }
        sort(ntp.begin(), ntp.end());
        for(int i = 1; i < n; i++) {
            ans = min(ans, ntp[i] - ntp[i - 1]);
        }
        ans = min(ans, minutes - ntp[n - 1] + ntp[0]);
        return ans;
    }
};