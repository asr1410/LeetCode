class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long ans = 0, sum = 0;
        priority_queue<pair<double, int>> maxpq;
        for(int i = 0; i < damage.size(); i++) {
            int t = health[i] / power + (health[i] % power != 0);
            double dps = (1.0 * damage[i]) / (1.0 * t);
            maxpq.emplace(dps, i);
            sum += damage[i];
        }
        while(maxpq.empty() == false) {
            int i = maxpq.top().second;
            maxpq.pop();
            int t = health[i] / power + (health[i] % power != 0);
            ans += sum * t;
            sum -= damage[i];
        }
        return ans;
    }
};