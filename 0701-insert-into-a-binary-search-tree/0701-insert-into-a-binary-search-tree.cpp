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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto curr = root;
        auto prev = root;
        while(curr) {
            if(curr->val < val) {
                prev = curr;
                curr = curr->right;
            } else {
                prev = curr;
                curr = curr->left;
            }
        }
        if(prev == nullptr) {
            return root = new TreeNode(val);
        } else if(prev->val < val) {
            prev->right = new TreeNode(val);
        } else {
            prev->left = new TreeNode(val);
        }
        return root;
    }
};