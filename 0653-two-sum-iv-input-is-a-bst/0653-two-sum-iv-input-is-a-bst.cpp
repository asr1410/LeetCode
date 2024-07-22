/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, vector<int> &nums) {
        if(root != nullptr) {
            traverse(root->left, nums);
            nums.push_back(root->val);
            traverse(root->right, nums);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        traverse(root, nums);
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if(nums[left] + nums[right] == k) {
                return true;
            } else if(nums[left] + nums[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};