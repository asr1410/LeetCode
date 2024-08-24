#include <vector>
using namespace std;

class FT {
public:
    vector<int> feg;
    int n;
    FT(int n) : n(n + 1) {
        feg.resize(this->n, 0);
    }
    
    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += feg[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    
    void update(int idx, int delt) {
        while(idx < this->n) {
            feg[idx] += delt;
            idx += (idx & -idx);
        }
    }
};

class NumArray {
public:
    FT f;
    vector<int> nums;
    int n;
    NumArray(vector<int>& nums) : f(nums.size()), nums(nums), n(nums.size()) {
        for(int i = 0; i < n; i++) {
            f.update(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int delt = val - nums[index];
        f.update(index + 1, delt);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return f.query(right + 1) - f.query(left);
    }
};
