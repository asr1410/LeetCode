class Solution {
public:
    void update(char& dir, int c) {
        if(dir == 'n') {
            if(c == -1) {
                dir = 'e';
            } else {
                dir = 'w';
            }
        } else if(dir == 'e') {
            if(c == -1) {
                dir = 's';
            } else {
                dir = 'n';
            }
        } else if(dir == 'w') {
            if(c == -1) {
                dir = 'n';
            } else {
                dir = 's';
            }
        } else {
            if(c == -1) {
                dir = 'w';
            } else {
                dir = 'e';
            }
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> uset;
        for(auto o : obstacles) {
            uset.emplace(o[0], o[1]);
        }
        int x = 0, y = 0;
        char dir = 'n';
        int ans = 0;
        for(int c : commands) {
            if(c > 0) {
                int n = c;
                if(dir == 'e') {
                    while(n and uset.find(make_pair(x + 1, y)) == uset.end()) {
                        x++, n--;
                    }
                } else if(dir == 'w') {
                    while(n and uset.find(make_pair(x - 1, y)) == uset.end()) {
                        x--, n--;
                    }
                } else if(dir == 'n') {
                    while(n and uset.find(make_pair(x, y + 1)) == uset.end()) {
                        y++, n--;
                    }
                } else {
                    while(n and uset.find(make_pair(x, y - 1)) == uset.end()) {
                        y--, n--;
                    }
                }
                ans = max(ans, x * x + y * y);
            } else {
                update(dir, c);
            }
        }
        return ans;
    }
};