class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> temp;
        temp.resize(nums.size());
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, temp, left, mid);
            mergeSort(nums, temp, mid + 1, right);
            merge(nums, temp, left, mid, right);
        }
    }

    void merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        for (int i = left; i <= right; ++i) {
            temp[i] = nums[i];
        }
        
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (temp[i] <= temp[j]) {
                nums[k++] = temp[i++];
            } else {
                nums[k++] = temp[j++];
            }
        }

        while (i <= mid) {
            nums[k++] = temp[i++];
        }
    }
};
