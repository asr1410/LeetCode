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
    vector<TreeNode*> temp;
    int mh = 0;
    int height(TreeNode* root) {
        if(!root) {
            return -1;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    void deepestNode(TreeNode* root, int height) {
        if(!root) {
            return;
        }
        if(height == mh) {
            temp.push_back(root);
        }
        deepestNode(root->left, height + 1);
        deepestNode(root->right, height + 1);
    }
    void path(TreeNode* root, TreeNode* target, vector<TreeNode*>& t, vector<TreeNode*>& p) {
        if(!root) {
            return;
        }
        t.push_back(root);
        if(root == target) {
            p = t;
            return;
        }
        path(root->left, target, t, p);
        path(root->right, target, t, p);
        t.pop_back();
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        mh = height(root);
        deepestNode(root, 0);
        if(temp.size() == 1) {
            return temp[0];
        }
        vector<TreeNode*> t, p1, p2;
        path(root, temp[0], t, p1);
        t.clear();
        path(root, temp[temp.size() - 1], t, p2);
        auto ans = root;
        for(int i = 0; i < p1.size(); i++) {
            if(p1[i] != p2[i]) {
                break;
            }
            ans = p1[i];
        }
        return ans;
    }
};