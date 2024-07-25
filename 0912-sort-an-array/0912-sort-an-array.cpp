class Solution {
public:
    void merge(vector<int> &nums, int left, int mid, int right) {
        vector<int> sorted;
        sorted.resize(right - left + 1);
        int i = left, j = mid + 1, idx = 0;
        while (i <= mid && j <= right) {
            if (nums[i] < nums[j]) {
                sorted[idx++] = nums[i++];
            } else {
                sorted[idx++] = nums[j++];
            }
        }
        while (i <= mid) {
            sorted[idx++] = nums[i++];
        }
        while (j <= right) {
            sorted[idx++] = nums[j++];
        }
        for(i = left, j = 0; j < idx; i++, j++) {
            nums[i] = sorted[j];
        }
    }

    void msort(vector<int> &nums, int left, int right) {
        if (left < right) {
            int mid = (left + right) >> 1;
            msort(nums, left, mid);
            msort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        msort(nums, 0, nums.size() - 1);
        return nums;
    }
};
