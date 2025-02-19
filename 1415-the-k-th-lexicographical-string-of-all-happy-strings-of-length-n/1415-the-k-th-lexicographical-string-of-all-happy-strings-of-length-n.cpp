class Solution {
private:
    const vector<char> hc = {'a', 'b', 'c'};
    set<string> ans;
    string temp;
    
    void helper(int n) {
        if (temp.size() == n) {
            ans.emplace(temp);
            return;
        }
        
        for (const char& c : hc) {
            if (temp.empty() || temp.back() != c) {
                temp.push_back(c);
                helper(n);
                temp.pop_back();
            }
        }
    }
    
public:
    string getHappyString(int n, int k) {
        helper(n);
        if (ans.size() < k) {
            return "";
        }
        auto it = ans.begin();
        advance(it, k - 1);
        return *it;
    }
};