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
    int maxdiff(TreeNode* r, int mx, int mn){
        if(r == NULL)
            return mx - mn;
        mx = max(mx, r->val);
        mn = min(mn, r->val);
        return max(maxdiff(r->left, mx, mn), maxdiff(r->right, mx, mn));
    }
    int maxAncestorDiff(TreeNode* r) {
        int mx = r->val;
        int mn = r->val;
        return maxdiff(r, mx, mn);
    }
};