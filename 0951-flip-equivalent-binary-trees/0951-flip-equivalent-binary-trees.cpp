class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            return false;
        }
            return (flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right)) 
                or (flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left));
    }
};
