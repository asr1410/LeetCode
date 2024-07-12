class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto &bill:bills) {
            if(bill == 20) {
                if(ten and five) {
                    ten--;
                    five--;
                } else if(five > 2) {
                    five -= 3;
                } else {
                    return false;
                }
            } else if(bill == 10) {
                if(five) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else {
                five++;
            }
        }
        return true;
    }
};