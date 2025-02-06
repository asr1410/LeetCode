class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        vector<int> v1;
        int n = nums.size();
        v1.reserve((n * (n - 1)) / 2);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                v1.push_back(nums[i] * nums[j]);
            }
        }

        unordered_map<int, int> ump;
        for(const int& v : v1) {
            ump[v]++;
        }
        
        int ans = 0;

        for(const auto& u : ump) {
            ans += (u.second * (u.second - 1)) / 2 * 8;
        }

        return ans;
    }
};