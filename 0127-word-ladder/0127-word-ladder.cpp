class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wl) {
        unordered_set<string> us(wl.begin(), wl.end());
        queue<string> q;
        
        q.push(b);
        int ans = 1;
        while(q.empty() == false) {
            int size = q.size();
            while(size--) {
                string t = q.front();
                q.pop();
                if(t == e) {
                    return ans;
                }
                for(int i = 0; i < t.size(); i++) {
                    char oc = t[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        t[i] = c;
                        if(us.find(t) != us.end()) {
                            q.push(t);
                            us.erase(t);
                        }
                    }
                    t[i] = oc;
                }
            }
            ans++;
        }
        return 0;
    }
};