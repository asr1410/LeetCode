class Solution {
public:
    int ans = 0;
    
    void search(TreeNode* node, int pre=0) {    
        if (!node->left and !node->right) // node is a leaf node, return the sum of path from root to node
            // this->ans += pre << 1 | node->val; // also work
            this->ans += pre * 2 + node->val;
        if (node->left) // node.left is not None, recursively find the sum node to leaf
            // search(node->left, pre << 1 | node->val); // also work
            search(node->left, pre * 2 + node->val);
        if (node->right) // node.right is not None, recursively find the sum node to leaf
            // search(node->right, pre << 1 | node->val); // also work
            search(node->right, pre * 2 + node->val);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        search(root);
        return this->ans;
    }
};