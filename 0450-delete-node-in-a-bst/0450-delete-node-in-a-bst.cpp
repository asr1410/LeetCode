class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root) {
            if (root->val > key) {
                root->left = deleteNode(root->left, key);
            } else if (root->val < key) {
                root->right = deleteNode(root->right, key);
            } else {
                if (root->left == nullptr) {
                    TreeNode* rightChild = root->right;
                    delete root;
                    return rightChild;
                } else if (root->right == nullptr) {
                    TreeNode* leftChild = root->left;
                    delete root;
                    return leftChild;
                }
                TreeNode* successor = findMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
    
private:
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
};
