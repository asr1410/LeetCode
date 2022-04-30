class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    }
    TreeNode *build(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int, int> &m)
    {
        if (prestart > preend or instart > inend)
            return NULL;
        TreeNode *root = new TreeNode(preorder[prestart]);
        int index = m[root->val];
        int lefts = index - instart;
        root->left = build(preorder, prestart + 1, prestart + lefts, inorder, instart, index - 1, m);
        root->right = build(preorder, prestart + lefts + 1, preend, inorder, index + 1, inend, m);
        return root;
    }
};