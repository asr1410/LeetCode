class Solution
{
public:
    vector<int> ans;
    int dist(TreeNode *root, TreeNode *target, int k)
    {
        if (root == nullptr)
            return 0;
        if (root == target)
        {
            nodes(target, k);
            return 1;
        }
        int left = dist(root->left, target, k);
        if (left != 0)
        {
            if (left == k)
                ans.push_back(root->val);
            else if (left < k)
                nodes(root->right, k - left - 1 );
            return 1 + left;
        }
        int right = dist(root->right, target, k);
        if (right != 0)
        {
            if (right == k)
                ans.push_back(root->val);
            else if (right < k)
                nodes(root->left, k - right - 1);
            return 1 + right;
        }
        return 0;
    }
    void nodes(TreeNode *target, int k)
    {
        if (target == nullptr)
            return;
        if (k == 0)
        {
            ans.push_back(target->val);
            return;
        }
        nodes(target->left, k - 1);
        nodes(target->right, k - 1);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        dist(root, target, k);
        return ans;
    }
};