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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        int psum = root->val;
        q.push(root);
        while(q.empty() == false) {
            int t = q.size();
            int nsum = 0;
            while(t--) {
                auto front = q.front();
                int tsum = 0;
                q.pop();
                if(front->left) {
                    tsum += front->left->val;
                    nsum += front->left->val;
                }
                if(front->right) {
                    tsum += front->right->val;
                    nsum += front->right->val;
                }
                if(front->left) {
                    front->left->val = tsum;
                    q.push(front->left);
                }
                if(front->right) {
                    front->right->val = tsum;
                    q.push(front->right);
                }
                front->val = psum - front->val;
            }
            psum = nsum;
        }
        return root;
    }
};