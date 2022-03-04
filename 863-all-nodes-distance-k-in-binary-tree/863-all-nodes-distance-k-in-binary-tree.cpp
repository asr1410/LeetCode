class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        vector<int> res;
        distanceK(root, target, K, res);
        return res;
    }

private:
    int distanceK(TreeNode *node, TreeNode *target, int K, vector<int> &res)
    {
        if (node == nullptr)
        {
            return 0;
        }
        if (node == target)
        {
            traverseSubtree(node, K, res);
            return 1;
        }
        int distLeft = distanceK(node->left, target, K, res);
        if (distLeft != 0)
        {
            if (distLeft == K)
            {
                res.push_back(node->val);
            }
            else if (distLeft < K)
            {
                traverseSubtree(node->right, K - distLeft - 1, res); // visit the right subtree looking for nodes at a given distance
            }
            return distLeft + 1; //  return distance to target + 1
        }
        int distRight = distanceK(node->right, target, K, res); // distance to target in the right subtree
        if (distRight != 0)
        {
            if (distRight == K)
            {
                res.push_back(node->val);
            }
            else if (distRight < K)
            {
                traverseSubtree(node->left, K - distRight - 1, res); // visit the left subtree looking for nodes at a given distance
            }
            return distRight + 1; //  return distance to target + 1
        }
        return 0; // if reached this place, then there is no target in the current subtree
    }
    void traverseSubtree(TreeNode *node, int K, vector<int> &res)
    {
        if (node == nullptr)
        {
            return;
        }
        if (K == 0)
        { // found a node at a given distance
            res.push_back(node->val);
            return;
        }
        traverseSubtree(node->left, K - 1, res);  // go down until we find a node at a distance of K
        traverseSubtree(node->right, K - 1, res); // (if the depth of the subtree allows us to do this)
    }
};