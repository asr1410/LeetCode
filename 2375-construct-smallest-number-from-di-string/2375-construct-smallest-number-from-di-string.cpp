class Solution {
public:
    vector<int> taken;
    vector<char> chars;
    string ans = "999999999";
    string temp;
    
    bool check(int& n, const string& temp, const string& pattern) {
        for(int i = 0; i < n - 1; i++) {
            if((pattern[i] == 'I' && temp[i] > temp[i + 1]) || (pattern[i] == 'D' && temp[i] < temp[i + 1])) {
                return false;
            }
        }
        return true;
    }
    
    void helper(int& n, string& pattern) {
        if(temp.size() == n) {
            if(check(n, temp, pattern)) {
                if(ans == "999999999" || stoi(temp) < stoi(ans)) {
                    ans = temp;
                }
            }
            return;
        }
        for(const char c : chars) {
            if(taken[c - '0'] == 0) {
                taken[c - '0'] = 1;
                temp.push_back(c);
                helper(n, pattern);
                temp.pop_back();
                taken[c - '0'] = 0;
            }
        }
    }
    
    string smallestNumber(string pattern) {
        int n = pattern.size() + 1;
        for(int i = 0; i < n; i++) {
            chars.push_back('1' + i);
        }
        taken.resize(n + 1, 0);
        temp.reserve(n);
        helper(n, pattern);
        return ans;
    }
};