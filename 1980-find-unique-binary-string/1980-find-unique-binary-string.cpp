class Solution {
public:
    vector<char> tc {'0', '1'};
    unordered_set<string> uset;
    string ans;
    bool helper(int& n) {
        if(ans.size() == n and uset.find(ans) == uset.end()) {
            return true;
        }
        if(ans.size() > n) {
            return false;
        }
        for(const char& c : tc) {
            ans.push_back(c);
            if(helper(n) == true) return true;
            ans.pop_back();
        }
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(const string& num : nums) {
            uset.emplace(num);
        }
        int n = nums[0].size();
        helper(n);
        return ans;
    }
};