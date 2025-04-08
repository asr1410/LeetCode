class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count[101] = {0}, n = nums.size(), i = n - 1;
        while(i >= 0) {
            count[nums[i]]++;
            if(count[nums[i]] > 1) {
                break;
            }
            i--;
        }
        return (i + 3) / 3;
    }
};