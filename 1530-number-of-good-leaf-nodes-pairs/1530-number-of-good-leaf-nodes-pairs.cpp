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
    vector<int> traverse(TreeNode *root, int dis) {
        if(root == nullptr) {
            return vector<int> (12);
        } else if(root->left == nullptr and root->right == nullptr) {
            vector<int> curr(12);
            curr[0] = 1;
            return curr;
        }
        auto left = traverse(root->left, dis);
        auto right = traverse(root->right, dis);
        vector<int> curr(12);
        for(int i = 0; i < 10; i++) {
            curr[i + 1] = left[i] + right[i];
        }
        curr[11] += left[11] + right[11];
        for(int d1 = 0; d1 <= dis; d1++) {
            for(int d2 = 0; d2 <= dis; d2++) {
                if(2 + d1 + d2 <= dis) {
                    curr[11] += left[d1] * right[d2];
                }
            }
        }
        return curr;
    }
    int countPairs(TreeNode* root, int distance) {
        return traverse(root, distance)[11];
    }
};