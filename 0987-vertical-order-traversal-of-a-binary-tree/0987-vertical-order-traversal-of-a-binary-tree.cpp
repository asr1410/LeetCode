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
    void traversal(TreeNode *root, vector<pair<int, pair<int, int>>> &store, int x, int y) {
        if(root == nullptr) {
            return;
        }
        store.push_back(make_pair(y, make_pair(x, root->val)));
        traversal(root->left, store, x + 1, y - 1);
        traversal(root->right, store, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int, pair<int, int>>> store;
        traversal(root, store, 0, 0);
        sort(store.begin(), store.end());
        vector<vector<int>> ans;
        vector<pair<int, int>> temp;
        for(int i = 0, start = 0; i < store.size(); i++) {
            if(i == 0 or start != store[i].first) {
                start = store[i].first;
                if(temp.empty() == false) {
                    vector<int> t;
                    sort(temp.begin(), temp.end());
                    for(auto &c:temp) {
                        t.push_back(c.second);
                    }
                    ans.push_back(t);
                    temp.clear();
                }
            }
            temp.push_back(make_pair(store[i].second.first, store[i].second.second));
        }
        if(temp.empty() == false) {
                    vector<int> t;
                    sort(temp.begin(), temp.end());
                    for(auto &c:temp) {
                        t.push_back(c.second);
                    }
                    ans.push_back(t);
                    temp.clear();
                }
        return ans;
    }
};