class NumArray {
public:
    vector<int> nums, bit;
    int n;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            add(i, nums[i]);
        }
    }
    
    void add(int idx, int delta) {
        for(int i = idx + 1; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }
    
    int sum(int idx) {
        int sum = 0;
        for(int i = idx + 1; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }
    
    int sumRange(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */