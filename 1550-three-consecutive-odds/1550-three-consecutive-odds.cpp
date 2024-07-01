class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 0, count = 0; i < arr.size(); i++) {
            if(arr[i] % 2) {
                count++;
                if(count == 3) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
        return false;
    }
};