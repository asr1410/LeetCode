class Solution {
public:
    unordered_set<string> tub;
    int cnt[26] = {0};
    string temp;
    void helper(int k, string& tiles) {
        if(k == tiles.size()) {
            tub.insert(temp);
            return;
        }
        for(const char& c : tiles) {
            if(cnt[c - 'A']) {
                cnt[c - 'A']--;
                temp.push_back(c);
                helper(k + 1, tiles);
                temp.pop_back();
                cnt[c - 'A']++;
            }
            helper(k + 1, tiles);
        }
    }
    int numTilePossibilities(string tiles) {
        for(const char& c : tiles) {
            cnt[c - 'A']++;
        }
        helper(0, tiles);
        return tub.size() - 1;
    }
};