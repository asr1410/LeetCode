#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> comb;
        comb.reserve(profit.size());
        for (int i = 0; i < profit.size(); i++) {
            comb.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(comb.begin(), comb.end());
        for (int i = 1; i < profit.size(); i++) {
            comb[i].second = max(comb[i].second, comb[i - 1].second);
        }
        int maxProfit = 0;
        for (int w : worker) {
            int left = 0, right = comb.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (comb[mid].first <= w) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (right >= 0) {
                maxProfit += comb[right].second;
            }
        }
        
        return maxProfit;
    }
};