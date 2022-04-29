class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int idx = 0;
        return build(preorder, inorder, idx, 0, inorder.size() - 1);
    }
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &idx, int left, int right)
    {
        if (left > right)
            return NULL;
        int pivot = left;
        while (inorder[pivot] != preorder[idx])
            pivot++;
        idx++;
        TreeNode *newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, idx, left, pivot - 1);
        newNode->right = build(preorder, inorder, idx, pivot + 1, right);
        return newNode;
    }
};