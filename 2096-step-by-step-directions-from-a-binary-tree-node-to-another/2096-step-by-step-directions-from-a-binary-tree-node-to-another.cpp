class Solution {
public:
    void findPath(TreeNode* root, int val, string &path, bool &found) {
        if (!root || found) return;
        if (root->val == val) {
            found = true;
            return;
        }
        path.push_back('L');
        findPath(root->left, val, path, found);
        if (found) return;
        path.pop_back();
        path.push_back('R');
        findPath(root->right, val, path, found);
        if (found) return;
        path.pop_back();
    }

    string getDirections(TreeNode* root, int sv, int dv) {
        string pathToSV, pathToDV;
        bool foundSV = false, foundDV = false;
        findPath(root, sv, pathToSV, foundSV);
        findPath(root, dv, pathToDV, foundDV);
        if (!foundSV || !foundDV) return "";
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
