class Solution {
public:
    void helper(vector<vector<int>> &image, int sr, int sc, int ncol, int ocol) {
        if (sr >= 0 && sr < image.size() && sc >= 0 && sc < image[0].size() && image[sr][sc] == ocol) {
            image[sr][sc] = ncol;
            helper(image, sr - 1, sc, ncol, ocol);
            helper(image, sr, sc - 1, ncol, ocol);
            helper(image, sr, sc + 1, ncol, ocol);
            helper(image, sr + 1, sc, ncol, ocol);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int ncol) {
        int ocol = image[sr][sc];
        if (ocol != ncol) {
            helper(image, sr, sc, ncol, ocol);
        }
        return image;
    }
};
