class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &data)
    {
        if (!root)
            return;
        inorder(root->left, data);
        data.push_back(root->val);
        inorder(root->right, data);
    }
    int i = 0;
    void sorttree(TreeNode *root, vector<int> &data)
    {
        if (!root)
            return;
        sorttree(root->left, data);
        root->val = data[i++];
        sorttree(root->right, data);
    }
    void recoverTree(TreeNode *root)
    {
        vector<int> data;
        inorder(root, data);
        sort(data.begin(), data.end());
        sorttree(root, data);
    }
};