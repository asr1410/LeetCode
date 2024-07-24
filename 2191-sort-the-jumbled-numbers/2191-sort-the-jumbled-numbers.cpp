class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto mapNumber = [&mapping](int num) {
            if (num == 0) return mapping[0];
            int mappedNumber = 0;
            int place = 1;
            while (num > 0) {
                int digit = num % 10;
                mappedNumber = mapping[digit] * place + mappedNumber;
                num /= 10;
                place *= 10;
            }
            return mappedNumber;
        };
        sort(nums.begin(), nums.end(), [&mapNumber](const int &a, const int &b) {
            int mappedA = mapNumber(a);
            int mappedB = mapNumber(b);
            return mappedA < mappedB;
        });

        return nums;
    }
};