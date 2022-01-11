class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        for(int i = j; i >= 0; i--)
            if(nums[i] != 0)
                nums[j--] = nums[i];
        int k = j;
        for(; j >= 0; j--)
            nums[j] = 0;
         j = nums.size() - 1;
        for(int i = j; i > k; i--)
            if(nums[i]!=1)
                nums[j--] = nums[i];
        for(; j > k; j--)
            nums[j] = 1;
            
    }
};