class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int left = 1;
        int right = pos.back() - pos.front();
        auto canPlaceBalls = [&](int distance) {
            int count = 1;
            int last_position = pos[0];
            for (int i = 1; i < pos.size(); ++i) {
                if (pos[i] - last_position >= distance) {
                    count++;
                    last_position = pos[i];
                    if (count == m) return true;
                }
            }
            return false;
        };

        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (canPlaceBalls(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};