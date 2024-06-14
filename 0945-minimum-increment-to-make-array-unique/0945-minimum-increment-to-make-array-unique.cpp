class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> map(100001, 0);
        
        // Populate the frequency map with counts of each number in nums
        for(int num : nums) {
            map[num]++;
        }
        
        int ans = 0;
        
        // Process the frequencies from 0 to 9999
        for(int i = 0; i < 100000; i++) {
            if(map[i] > 1) {
                int temp = map[i] - 1; // Calculate the excess count
                ans += temp; // Increment the answer by the excess count
                map[i + 1] += temp; // Move the excess to the next number
            }
        }
        
        // Handle the case for the number 100000 specifically
        ans += (map[100000] * (map[100000] - 1)) / 2;
        
        return ans;
    }
};
