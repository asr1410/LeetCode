class Solution {
public:
    int mn = INT_MAX;
    int mx = INT_MIN;

    void traversal(TreeNode *root, unordered_map<int, vector<pair<int, int>>> &store, int x, int y) {
        if (!root) return;
        mn = min(mn, y);
        mx = max(mx, y);
        store[y].push_back(make_pair(x, root->val));
        traversal(root->left, store, x + 1, y - 1);
        traversal(root->right, store, x + 1, y + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<pair<int, int>>> store;
        traversal(root, store, 0, 0);
        vector<vector<int>> ans;

        for (int i = mn; i <= mx; i++) {
            if (store.find(i) != store.end()) {
                sort(store[i].begin(), store[i].end());
                vector<int> temp;
                for (const auto& p : store[i]) {
                    temp.push_back(p.second);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
