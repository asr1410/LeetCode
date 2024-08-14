class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    int countPairs(const std::vector<int>& nums, int distance) {
        int count = 0;
        int n = nums.size();
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            while (nums[right] - nums[left] > distance) {
                ++left;
            }
            count += (right - left);
        }
        
        return count;
    }
};
