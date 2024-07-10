class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        map<int, int> mp;
        for(auto c:hand) mp[c]++;
        for(auto c:mp) {
            if(mp[c.first] > 0) {
                for(int i = gs - 1; i >= 0; i--) {
                    if((mp[c.first + i] -= mp[c.first]) < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};