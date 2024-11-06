class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> snums = nums;
        sort(snums.begin(), snums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            int idx = lower_bound(snums.begin(), snums.end(), nums[i]) - snums.begin();
            if(idx != i) {
                if(idx < i) {
                    for(int j = i; j >= idx; j--) {
                        if(__builtin_popcount(nums[i]) != __builtin_popcount(nums[j])) {
                            return false;
                        }
                    }
                } else {
                    for(int j = i; j <= idx; j++) {
                        if(__builtin_popcount(nums[i]) != __builtin_popcount(nums[j])) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
