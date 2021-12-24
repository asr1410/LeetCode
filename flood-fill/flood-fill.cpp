class Solution {
public:
    void recursive(vector<vector<int>> &image, int m, int n, int old, int newcol)
{
    if (m < 0 || n < 0 || m >= image.size() || n >= image[0].size() || image[m][n] != old)
        return;
    image[m][n] = newcol;
    recursive(image, m + 1, n, old, newcol);
    recursive(image, m - 1, n, old, newcol);
    recursive(image, m, n + 1, old, newcol);
    recursive(image, m, n - 1, old, newcol);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
        recursive(image, sr, sc, image[sr][sc], newColor);
    return image;
    }
};