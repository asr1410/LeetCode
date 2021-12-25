class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(numbers[left] + numbers[right] != target)
        {
            if(numbers[left]+numbers[right]>target)
                right--;
            else
                left++;
        }
        return {++left, ++right};
    }
};