class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() & 1 or (s.back() == '(' and locked.back() == '1')) {
            return false;
        }
        vector<pair<char, char>> temp;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(temp.empty() == false and temp.back().first == '(' and s[i] == ')') {
                temp.pop_back();
            } else {
                temp.push_back(make_pair(s[i], locked[i]));
            }
        }
        for(auto t : temp) {
            cout << t.first << "|" << t.second << " ";
        }

        if(temp.size() & 1) {
            return false;
        }
        int cz = 0, co = 0;
        for(auto t : temp) {
            cz += t.second == '0';
            co += t.second == '1';
            if(cz < co) {
                return false;
            }
        }
        return true;
    }
};