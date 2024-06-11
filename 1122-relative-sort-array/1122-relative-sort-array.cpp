class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0);
        for (auto num : arr1) {
            count[num]++;
        }
        vector<int> ans;
        ans.reserve(arr1.size());
        for (auto num : arr2) {
            while (count[num]) {
                ans.push_back(num);
                count[num]--;
            }
        }
        for (int i = 0; i < 1001; i++) { // Corrected the condition to 'i < 1001' instead of 'i <= 1001'
            while (count[i]) {
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};
