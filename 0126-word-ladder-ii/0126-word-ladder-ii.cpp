class Solution {
public:
    unordered_map<string, int> umap;
    vector<vector<string>> ans;
    string begin;

    void dfs(string s, vector<string>& seq) {
        if (begin == s) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = umap[s];
        for (int i = 0; i < s.size(); i++) {
            char org = s[i];
            for (char c = 'a'; c <= 'z'; c++) {
                s[i] = c;
                if (umap.count(s) && umap[s] + 1 == steps) {
                    seq.push_back(s);
                    dfs(s, seq);
                    seq.pop_back();
                }
            }
            s[i] = org;
        }
    }

    vector<vector<string>> findLadders(string s, string e, vector<string>& wl) {
        unordered_set<string> uset(wl.begin(), wl.end());
        if (uset.count(e) == 0) {
            return ans;
        }

        begin = s;
        queue<string> q;
        uset.erase(s);
        q.emplace(s);
        umap[s] = 1;

        while (!q.empty()) {
            string front = q.front();
            q.pop();
            int steps = umap[front];

            if (front == e) {
                break;
            }

            for (int i = 0; i < front.size(); i++) {
                char org = front[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    front[i] = c;
                    if (uset.count(front)) {
                        umap[front] = steps + 1;
                        q.emplace(front);
                        uset.erase(front);
                    }
                }
                front[i] = org;
            }
        }

        if (umap.count(e) != 0) {
            vector<string> seq;
            seq.emplace_back(e);
            dfs(e, seq);
        }

        return ans;
    }
};
