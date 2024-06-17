class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = static_cast<long>(sqrt(c));
        while (left <= right) {
            long long sqsm = static_cast<long long>(left) * left + static_cast<long long>(right) * right;
            if (sqsm == c) {
                return true;
            } else if (sqsm > c) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};