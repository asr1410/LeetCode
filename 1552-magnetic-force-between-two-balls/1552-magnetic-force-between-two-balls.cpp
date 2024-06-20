class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int left = 1, right = pos.back() - pos.front();
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int count = 1;
            int last_position = pos.front();
            for (int i = 1; i < pos.size(); i++) {
                if (pos[i] - last_position >= mid) {
                    last_position = pos[i];
                    count++;
                    if (count == m) break;
                }
            }
            if (count == m) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};