/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* curr, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>> &g, unordered_set<TreeNode*> &l) {
        if(curr == nullptr) {
            return;
        }
        if(curr->left == nullptr and curr->right == nullptr) {
            l.insert(curr);
        }
        if(prev != nullptr) {
            g[prev].push_back(curr);
            g[curr].push_back(prev);
        }
        traverse(curr->left, curr, g, l);
        traverse(curr->right, curr, g, l);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> g;
        unordered_set<TreeNode*> l;
        traverse(root, nullptr, g, l);
        int ans = 0;
        for(auto leaf:l) {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> vis;
            q.push(leaf);
            vis.insert(leaf);
            for(int i = 0; i <= distance; i++) {
                int size = q.size();
                for(int j = 0; j < size; j++) {
                    auto curr = q.front();
                    q.pop();
                    if(l.count(curr) and curr != leaf) {
                        ans++;
                    }
                    if(g.count(curr)) {
                        for(auto neigh:g[curr]) {
                            if(!vis.count(neigh)) {
                                q.push(neigh);
                                vis.insert(neigh);
                            }
                        }
                    }
                }
            }
        }
        return ans / 2;
    }
};