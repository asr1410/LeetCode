class Solution {
    #define ll long long
public:
ll mod=1e9+7;
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = (res * x)%p;
        y = y >> 1;
        x = (x * x)%p;
    }
    return res % p;
}

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1) return nums;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        ll n=nums.size(),mx=0;
        for(ll i=0;i<n;i++) {
            pq.push({(ll)nums[i],i});
            mx=max(mx,(ll)nums[i]);
        }
        while(k && pq.top().first*multiplier<=mx) {
            auto it=pq.top();
            pq.pop();
            it.first*=multiplier;
            pq.push(it);
            k--;
        }
        vector<pair<ll,ll>> v;
        while(!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }
        ll x=k/n,y=k%n;
        ll a=power(multiplier,x,mod);
        for(int i=0;i<n;i++) {
            v[i].first=(v[i].first*a)%mod;
        }
        for(int i=0;i<y;i++) {
            v[i].first=(v[i].first*multiplier)%mod;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[v[i].second]=v[i].first;
        }
        return ans;
    }
};