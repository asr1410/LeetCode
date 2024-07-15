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
    bool check = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(check == false) {
            return false;
        } else if(p == nullptr and q == nullptr) {
            return true;
        } else if(p == nullptr and q != nullptr) {
            check = false;
            return false;
        } else if(p != nullptr and q == nullptr) {
            check = false;
            return false;
        } else if(p->val != q->val) {
            check = false;
            return false;
        }
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);
        return check;
    }
};