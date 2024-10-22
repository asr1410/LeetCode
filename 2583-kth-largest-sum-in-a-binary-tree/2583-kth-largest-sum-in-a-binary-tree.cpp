class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<unsigned long long> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int len = q.size();
            unsigned long long temp = 0;
            
            while (len--) {
                auto front = q.front();
                q.pop();
                temp += front->val;
                
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            ans.push_back(temp);
        }
        
        if (k > ans.size()) return -1;
        
        sort(ans.begin(), ans.end(), greater<unsigned long long>());
        return ans[k - 1];
    }
};