class Solution {
public:
    int minDays(std::vector<int>& bloomDays, int m, int k) {
        if (m > bloomDays.size() / k) {
            return -1;
        }
        int left = *min_element(bloomDays.begin(), bloomDays.end());
        int right = *max_element(bloomDays.begin(), bloomDays.end());
        int n = bloomDays.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            int bouquets = 0, flowers = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDays[i] <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }
            if (bouquets < m) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};