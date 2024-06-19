class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        int n = bd.size();
        if (m > n / k) {
            return -1;
        }
        int l = 1, r = *max_element(bd.begin(), bd.end());
        auto canMakeBouquets = [&](int days) {
            int bouquets = 0, flowers = 0;
            for (int bloom : bd) {
                if (bloom <= days) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
                if (bouquets >= m) {
                    return true;
                }
            }
            return false;
        };
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canMakeBouquets(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};