class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> uset;
        return maxUniqueSplitHelper(s, 0, uset);
    }
    
private:
    int maxUniqueSplitHelper(string &s, int start, unordered_set<string> &uset) {
        if (start == s.size()) {
            return uset.size();
        }
        
        int maxCount = 0;
        for (int end = start + 1; end <= s.size(); end++) {
            string substring = s.substr(start, end - start);
            if (uset.insert(substring).second) {
                maxCount = max(maxCount, maxUniqueSplitHelper(s, end, uset));
                uset.erase(substring);
            }
        }
        return maxCount;
    }
};
