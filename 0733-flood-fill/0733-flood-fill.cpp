class Solution {
public:
    int dirr[4] = {-1, 0, 0, 1};
    int dirc[4] = {0, -1, 1, 0};
    int rows = 0;
    int cols = 0;
    void dfs(vector<vector<int>>& image, int row, int col, int& ocolor, int& ncolor) {
        image[row][col] = ncolor;
        for(int i = 0; i < 4; i++) {
            int urow = row + dirr[i];
            int ucol = col + dirc[i];
            if(urow >= 0 and ucol >= 0 and urow < rows and ucol < cols and image[urow][ucol] == ocolor) {
                dfs(image, urow, ucol, ocolor, ncolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int color) {
        rows = image.size(), cols = image[0].size();
        int ocolor = image[sr][sc];
        if(ocolor != color) {
            dfs(image, sr, sc, ocolor, color);
        }
        return image;
    }
};