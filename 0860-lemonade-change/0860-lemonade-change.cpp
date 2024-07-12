class Solution {
public:
    bool check(int bill, int &five, int &ten) {
        if(bill == 20) {
            if(ten > 0 && five > 0) {
                ten--;
                five--;
            } else if(five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        } else if(bill == 10) {
            if(five > 0) {
                five--;
                ten++;
            } else {
                return false;
            }
        } else {
            five++;
        }
        return true;
    }

    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int bill : bills) {
            if(!check(bill, five, ten)) {
                return false;
            }
        }
        return true;
    }
};