class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                int next = i;
                while(nums[next]==0 && next < nums.size() - 1)
                    next++;
                swap(nums[i], nums[next]);
            }
        }
    }
};