class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    }
    TreeNode *build(vector<int> &postorder, int poststart, int postend, vector<int> &inorder, int instart, int inend, map<int, int> &m)
    {
        if (poststart > postend or instart > inend)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postend]);
        int index = m[root->val];
        int left = index - instart;
        root->left = build(postorder, poststart, poststart + left - 1, inorder, instart, index - 1, m);
        root->right = build(postorder, poststart + left, postend - 1, inorder, index + 1, inend, m);
        return root;
    }
};