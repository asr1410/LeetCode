class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        if (helper(root, toDelete, ans)) {
            ans.push_back(root);
        }
        return ans;
    }

private:
    TreeNode* helper(TreeNode* node, unordered_set<int>& toDelete, vector<TreeNode*>& ans) {
        if (!node) return nullptr;
        node->left = helper(node->left, toDelete, ans);
        node->right = helper(node->right, toDelete, ans);
        if (toDelete.find(node->val) != toDelete.end()) {
            if (node->left) ans.push_back(node->left);
            if (node->right) ans.push_back(node->right);
            return nullptr;
        }
        return node;
    }
};