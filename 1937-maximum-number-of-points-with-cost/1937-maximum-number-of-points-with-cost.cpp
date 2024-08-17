#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        if (rows == 0) return 0;
        
        int cols = points[0].size();
        if (cols == 0) return 0;
        
        vector<long long> prev(cols, 0), curr(cols, 0);

        for (int col = 0; col < cols; ++col) {
            prev[col] = points[0][col];
        }

        for (int row = 1; row < rows; ++row) {
            long long maxLeft = prev[0];
            vector<long long> left(cols, 0), right(cols, 0);
            
            for (int col = 0; col < cols; ++col) {
                maxLeft = max(maxLeft - 1, prev[col]);
                left[col] = maxLeft;
            }

            long long maxRight = prev[cols - 1];
            for (int col = cols - 1; col >= 0; --col) {
                maxRight = max(maxRight - 1, prev[col]);
                right[col] = maxRight;
            }

            for (int col = 0; col < cols; ++col) {
                curr[col] = points[row][col] + max(left[col], right[col]);
            }

            prev = curr;
        }

        long long result = *max_element(prev.begin(), prev.end());

        return result;
    }
};
