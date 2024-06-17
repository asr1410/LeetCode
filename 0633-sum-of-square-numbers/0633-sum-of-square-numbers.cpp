class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned long long left = 0, right = sqrt(c);
        while(left <= right) {
            unsigned long long sqsm = left * left + right * right;
            if(sqsm == c) {
                return true;
            } else if(sqsm > c) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};