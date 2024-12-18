class NumArray {
private:
    vector<int> nums;
    vector<int> bit;
    int n;

    void add(int index, int delta) {
        for (int i = index + 1; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefixSum(int index) {
        int sum = 0;
        for (int i = index + 1; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            add(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
