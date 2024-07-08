class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mnh;
        for(auto num:nums) {
            if(mnh.size() == k and num > mnh.top()) {
                mnh.pop();
                mnh.push(num);
            } else if(mnh.size() < k) {
                mnh.push(num);
            }
        }
        return mnh.top();
    }
};
