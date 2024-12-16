class Solution {
public:
    vector<int> getFinalState(vector<int>& v, int k, int m) {
        int n = v.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<n;i++) {
            q.push({v[i],i});
        }
        while(k--) {
            pair<int,int>p=q.top();
            q.pop();
            int val=p.first;
            int idx = p.second;
            v[idx]=val*m;
            q.push({val*m,idx});
        }
        return v;
    }
};