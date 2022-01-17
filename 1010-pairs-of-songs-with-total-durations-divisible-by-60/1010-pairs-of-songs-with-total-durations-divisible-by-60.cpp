class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        int mark[60] = {};
        for(auto &&i : time)
        {
            int rem = i % 60;
            if(!rem)
                count += mark[rem];
            else
                count += mark[60 - rem];
            mark[rem]++;
        }
        return count;
    }
};