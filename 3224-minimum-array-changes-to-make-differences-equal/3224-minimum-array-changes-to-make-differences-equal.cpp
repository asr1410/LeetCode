class Solution {
public:
    int find(vector<int> &diff, int &val) {
        int left = 0, right = diff.size() - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(diff[mid] < val) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
    
    int minChanges(vector<int>& a, int k) {
        unordered_map<int, int> umap;
        int n = a.size();
        vector<int> diff(n / 2);
        for (int i = 0; i < n / 2; i++) {
            diff[i] = max({a[i], a[n - i - 1], k - a[i], k - a[n - i - 1]});
            umap[abs(a[i] - a[n - i - 1])]++;
        }
        sort(diff.begin(), diff.end());
        int ans = INT_MAX;
        for (const auto &it : umap) {
            int val = it.first;
            int fq = it.second;
            ans = min(ans, n / 2 - fq + find(diff, val));
        }
        return ans;
    }
};
