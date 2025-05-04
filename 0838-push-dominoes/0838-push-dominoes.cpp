class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> ldir, rdir;
        ldir.resize(n);
        rdir.resize(n);
        for(int i = 0; i < n; i++) {
            ldir[i] = d[i] == 'L' ? 1 : 0;
            rdir[i] = d[i] == 'R' ? 1 : 0;
        }
        for(int i = 1; i < n; i++) {
            if(rdir[i - 1] and rdir[i] == 0 and d[i] != 'L') {
                rdir[i] = rdir[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            if(ldir[i + 1] and ldir[i] == 0 and d[i] != 'R') {
                ldir[i] = ldir[i + 1] + 1;
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << rdir[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < n; i++) {
        //     cout << ldir[i] << " ";
        // }
        // cout << endl;
        string ans;
        for(int i = 0; i < n; i++) {
            if(ldir[i] == rdir[i]) {
                ans.push_back('.');
            } else if(ldir[i] and rdir[i] == 0) {
                ans.push_back('L');
            } else if(ldir[i] == 0 and rdir[i]) {
                ans.push_back('R');
            } else if(ldir[i] > rdir[i]) {
                ans.push_back('R');
            } else {
                ans.push_back('L');
            }
        }
        return ans;
    }
};