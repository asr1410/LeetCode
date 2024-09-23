class Solution {
public:
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        using T = tuple<long long, long long, int>;
        priority_queue<T, vector<T>, greater<T>> minpq;
        for(auto t : wt) {
            minpq.emplace(t, t, 1);
        }
        while(mh-- > 1) {
            auto [tt, t, m] = minpq.top();
            minpq.pop();
            tt += t * (m + 1);
            minpq.emplace(tt, t, m + 1);
        }
        return get<0>(minpq.top());
    }
};