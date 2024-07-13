class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, pair<int, int>>> store;
        for (int i = 0; i < positions.size(); i++) {
            store.push_back(make_pair(positions[i], make_pair(healths[i], directions[i] == 'R')));
        }
        sort(store.begin(), store.end());
        stack<pair<int, pair<int, int>>> st;
        st.push(store[0]);
        int i = 1, n = positions.size();
        while (i < n) {
            while(i < n and st.empty() == false and st.top().second.second == 1 and store[i].second.second == 0 and store[i].second.first != 0) {
                auto top = st.top();
                st.pop();
                if(top.second.first == store[i].second.first) {
                    store[i].second.first = 0;
                } else if(top.second.first > store[i].second.first) {
                    top.second.first--;
                    store[i].second.first = 0;
                    st.push(top);
                } else {
                    store[i].second.first--;
                }
            }
            if(store[i].second.first > 0)
                st.push(store[i]);
            i++;
        }
        unordered_map<int, int> umap;
        for(int i = 0; i < n; i++) {
            umap[positions[i]] = i;
        }
        vector<pair<int, int>> temp;
        while (!st.empty()) {
            temp.push_back(make_pair(umap[st.top().first], st.top().second.first));
            st.pop();
        }
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(auto &it:temp)
            ans.push_back(it.second);
        return ans;
    }
};