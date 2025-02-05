class Solution {
public:
    int maxFreeTime(int t, vector<int>& st, vector<int>& et) {
        vector<int> omset;
        vector<pair<int, int>> bar;
        int n = st.size();
        bar.reserve(n + 2);
        omset.reserve(n + 2);
        bar.emplace_back(0, 0);
        int ans = 0;

        for (int i = 0, temp = 0; i < n; i++) {
            temp = st[i] - bar.back().second;
            ans = max(ans, temp);
            omset.emplace_back(temp);
            bar.emplace_back(st[i], et[i]);
        }

        omset.emplace_back(t - bar.back().second);
        bar.emplace_back(t, t);
        sort(omset.begin(), omset.end());

        for(auto num : omset) {
            cout << num << " " ;
        }
        cout << endl;
        n++; 

        for (int i = 1, prev = bar[1].first - bar[0].second, curr, gap, rc, ac; i < n; i++) {
            curr = bar[i + 1].first - bar[i].second;
            gap = bar[i].second - bar[i].first;
            rc = (prev >= gap) + (curr >= gap);
            ac = omset.size() - (lower_bound(omset.begin(), omset.end(), gap) - omset.begin());

            if (ac > rc) {
                ans = max(ans, prev + gap + curr);
            } else if (ac == rc) {
                ans = max(ans, prev + curr);
            }

            cout << curr << " " << gap << " " << rc << " " << ac << " " << ans << endl;
            prev = curr;
        }
        return ans;
    }
};
