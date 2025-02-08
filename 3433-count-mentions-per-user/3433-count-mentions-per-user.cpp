class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            if(stoi(a[1]) < stoi(b[1]))
                return true;
            if(a[0] != b[0] and a[0] == "OFFLINE") {
                return true;
            }
            return false;
        });
        vector<int> on(n, 0);
        vector<int> cnt(n, 0);
        for(const auto& event : events) {
            auto msg = event[0];
            auto tim = stoi(event[1]);
            auto men = event[2];
            if(msg == "MESSAGE") {
                if(men == "ALL") {
                    for(int i = 0; i < n; i++) {
                        cnt[i]++;
                    }
                } else if(men == "HERE") {
                    for(int i = 0; i < n; i++) {
                        cnt[i] += on[i] <= tim;
                    }
                } else {
                    stringstream ss(men);
                    string temp;
                    char sep = ' ';
                    while(getline(ss, temp, sep)) {
                        cnt[stoi(temp.substr(2))]++;
                    }
                }
            } else {
                on[stoi(men)] = tim + 60;
            }
        }
        return cnt;
        // 61 62 0
        // 0 0 1
        // 1 0 2
    }
};