#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    long long lcmf(int i, int n, vector<int> nums) {
        long long ans = 1;
        vector<int> prime_counts(31, 0);
        
        for (int k = 0; k < n; k++) {
            if (i != k) {
                for (int j = 2; j < 31; j++) {
                    int count = 0;
                    while (nums[k] % j == 0) {
                        count++;
                        nums[k] /= j;
                    }
                    prime_counts[j] = max(prime_counts[j], count);
                }
            }
        }
        
        for (int j = 2; j < 31; j++) {
            ans *= pow(j, prime_counts[j]);
        }
        return ans;
    }
    
    int gcdf(int i, int n, vector<int>& nums) {
        int ans = 1;
        
        for (int j = 2; j < 31; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (i != k && nums[k] % j == 0) {
                    cnt++;
                }
            }
            if ((i == -1 && cnt == n) || (i != -1 && cnt == n - 1)) {
                ans = j;
            }
        }
        return ans;
    }

    long long maxScore(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0] * nums[0];
        }
        long long ans = 0;
        int n = nums.size();
        for (int i = -1; i < n; i++) {
            long long l = lcmf(i, n, nums);
            int g = gcdf(i, n, nums);
            ans = max(ans, l * g);
        }
        return ans;
    }
};
