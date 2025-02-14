class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        unordered_map<int, int> umpe;
        unordered_map<int, vector<int>> umpg;

        int m = g.size(), n = e.size(), mx = *max_element(g.begin(), g.end());

        for(int i = 0; i < m; i++) {
            umpg[g[i]].emplace_back(i);
        }

        for(int i = 0; i < n; i++) {
            if(umpe.find(e[i]) == umpe.end()) {
                umpe[e[i]] = i;
            }
        }

        vector<pair<int, int>> ne;
        for(const auto& it : umpe) {
            ne.emplace_back(it.second, it.first);
        }
        sort(ne.begin(), ne.end());
        
        // for(auto it : ne) {
        //     cout << it.first << " " << it.second << endl;
        // }

        vector<int> ans(m, -1);
        int val, add;
        for(const auto& it1 : ne) {
            val = it1.second, add = val;
            while(val <= mx) {
                if(umpg.find(val) != umpg.end()) {
                    for(const int& it2 : umpg[val]) {
                        ans[it2] = it1.first;
                    }
                    umpg[val].clear();
                    umpg.erase(val);
                }
                val += add;
            }
        }
        return ans;
    }
};