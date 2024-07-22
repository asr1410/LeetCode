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
    int i = 0;
    void traverse(TreeNode* root, vector<int> &nums) {
        if(root != nullptr) {
            traverse(root->left, nums);
            nums.push_back(root->val);
            traverse(root->right, nums);
        }
    }
    void update(TreeNode* root, vector<int> &nums) {
        if(root != nullptr) {
            update(root->left, nums);
            root->val = nums[i++];
            update(root->right, nums);
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        traverse(root, nums);
        sort(nums.begin(), nums.end());
        update(root, nums);
    }
};