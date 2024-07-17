class Solution {
public:
    void del(TreeNode* root, int d, unordered_map<int, TreeNode*>& umap, bool& check) {
        if (check || root == nullptr) {
            return;
        }
        if (root->left && root->left->val == d) {
            check = true;
            if (root->left->left) {
                umap[root->left->left->val] = root->left->left;
            }
            if (root->left->right) {
                umap[root->left->right->val] = root->left->right;
            }
            root->left = nullptr;
        } else if (root->right && root->right->val == d) {
            check = true;
            if (root->right->left) {
                umap[root->right->left->val] = root->right->left;
            }
            if (root->right->right) {
                umap[root->right->right->val] = root->right->right;
            }
            root->right = nullptr;
        } else {
            del(root->left, d, umap, check);
            del(root->right, d, umap, check);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, TreeNode*> umap;
        vector<TreeNode*> ans;
        umap[root->val] = root;
        for (int d : to_delete) {
            if (umap.find(d) != umap.end()) {
                if (umap[d]->left) {
                    umap[umap[d]->left->val] = umap[d]->left;
                }
                if (umap[d]->right) {
                    umap[umap[d]->right->val] = umap[d]->right;
                }
                umap.erase(d);
            } else {
                for (auto it : umap) {
                    bool check = false;
                    del(it.second, d, umap, check);
                    if (check) {
                        break;
                    }
                }
            }
        }

        for (auto it : umap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};