class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int, TreeNode*>> umap;
        
        for(int i = 0; i < descriptions.size(); i++) {
            int parent = descriptions[i][0], child = descriptions[i][1], left = descriptions[i][2];

            if(umap.find(parent) == umap.end()) {
                umap[parent] = {0, new TreeNode(parent)};
            }
            if(umap.find(child) == umap.end()) {
                umap[child] = {0, new TreeNode(child)};
            }
            if(left == 1) {
                umap[parent].second->left = umap[child].second;
            } else {
                umap[parent].second->right = umap[child].second;
            }
            umap[child].first++;
        }

        for(auto &it : umap) {
            if(it.second.first == 0)
                return it.second.second;
        }
        return nullptr;
    }
};
