class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr || root->right == nullptr) {
                TreeNode* temp = (root->left != nullptr) ? root->left : root->right;
                delete root;
                return temp;
            } else {
                TreeNode* successorParent = root;
                TreeNode* successor = root->right;
                
                while (successor->left != nullptr) {
                    successorParent = successor;
                    successor = successor->left;
                }
                
                root->val = successor->val;
                
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};
