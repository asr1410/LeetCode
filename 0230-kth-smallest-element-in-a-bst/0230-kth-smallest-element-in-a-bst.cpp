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
    void traverse(TreeNode* root, int &k, int &ans) {
        if(k == 0 or root == nullptr) {
            return;
        }
        traverse(root->left, k, ans);
        k--;
        if(k == 0) {
            ans = root->val;
        }  
        traverse(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        traverse(root, k, ans);
        return ans;
    }
};