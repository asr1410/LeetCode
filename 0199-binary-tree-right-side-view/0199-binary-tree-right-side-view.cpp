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
    int mx = INT_MIN;

    void traverse(TreeNode* root, unordered_map<int, pair<int, int>> &store, int x, int y) {
        if (root == nullptr) {
            return;
        }
        if (store.find(x) != store.end()) {
            if (store[x].first < x) {
                store[x].first = y;
                store[x].second = root->val;
            }
        } else {
            mx = max(mx, x);
            store[x] = {y, root->val};
        }
        traverse(root->left, store, x + 1, y - 1);
        traverse(root->right, store, x + 1, y + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int, pair<int, int>> store;
        traverse(root, store, 0, 0);
        vector<int> ans;
        for (int i = 0; i <= mx; i++) {
            if (store.find(i) != store.end()) {
                ans.push_back(store[i].second);
            }
        }
        return ans;
    }
};
