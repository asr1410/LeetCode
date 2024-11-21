class Solution {
public:
   int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       vector<vector<vector<int>>> mat(m, vector<vector<int>> (n, vector<int> (5, 0)));
       
       for(auto wall : walls) {
           mat[wall[0]][wall[1]][0] = 2;
       }
       
       for(auto guard : guards) {
           int x = guard[0], y = guard[1];
           mat[x][y][0] = mat[x][y][1] = mat[x][y][2] = mat[x][y][3] = mat[x][y][4] = 1;
           
           for(int i = y - 1; i >= 0 && mat[x][i][1] == 0 && mat[x][i][3] == 0 && mat[x][i][0] != 2; i--) {
               mat[x][i][0] = 1;
               mat[x][i][1] = 1;
           }
           
           for(int i = x - 1; i >= 0 && mat[i][y][2] == 0 && mat[i][y][4] == 0 && mat[i][y][0] != 2; i--) {
               mat[i][y][0] = 1;
               mat[i][y][2] = 1;
           }
           
           for(int i = y + 1; i < n && mat[x][i][3] == 0 && mat[x][i][1] == 0 && mat[x][i][0] != 2; i++) {
               mat[x][i][0] = 1;
               mat[x][i][3] = 1;
           }
           
           for(int i = x + 1; i < m && mat[i][y][4] == 0 && mat[i][y][2] == 0 && mat[i][y][0] != 2; i++) {
               mat[i][y][0] = 1;
               mat[i][y][4] = 1;
           }
       }
       
       int ans = 0;
       for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
               ans += mat[i][j][0] == 0;
           }
       }
       return ans;
   }
};