class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> num(nums.size());
        int i = 0;
        int j = nums.size() - 1;
        int largest = j;
        while(i <= j)
        {
            if(nums[i]*nums[i]>=nums[j]*nums[j])
            {
                num[largest--] = nums[i]*nums[i++];
            }
            else
            {
                num[largest--] = nums[j]*nums[j--];
            }
        }
        return num;
    }
};