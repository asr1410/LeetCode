class Solution {
public:
    bool findPath(TreeNode* root, int val, string &path) {
        if (!root) return false;
        if (root->val == val) return true;
        path.push_back('L');
        if (findPath(root->left, val, path)) return true;
        path.pop_back();
        path.push_back('R');
        if (findPath(root->right, val, path)) return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int sv, int dv) {
        string pathToSV, pathToDV;
        if (!findPath(root, sv, pathToSV) || !findPath(root, dv, pathToDV)) return "";
        int i = 0;
        while (i < pathToSV.size() && i < pathToDV.size() && pathToSV[i] == pathToDV[i]) {
            i++;
        }
        string upPath = string(pathToSV.begin() + i, pathToSV.end());
        string directions = string(upPath.size(), 'U');
        directions += pathToDV.substr(i);      
        return directions;
    }
};