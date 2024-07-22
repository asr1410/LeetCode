class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        
        inorderTraversal(root, prev, first, second);
        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
    
    void inorderTraversal(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
        if (root == nullptr) return;
        
        inorderTraversal(root->left, prev, first, second);
        
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        
        inorderTraversal(root->right, prev, first, second);
    }
};
