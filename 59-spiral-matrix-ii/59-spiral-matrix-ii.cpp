class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>m(n,vector<int>(n,0));
        int c=1;
        int left=0,right=n-1,top=0,bottom=n-1;
        while(left<=right && top<=bottom){
            
                for(int i=left;i<=right;i++){
                    m[top][i]=c;
                    c++;
                }
                top++;
            
                for(int i=top;i<=bottom;i++){
                   m[i][right]=c;
                    c++; 
                }
                right--;
            
                for(int i=right;i>=left;i--){
                    m[bottom][i]=c;
                    c++;
                }
                bottom--;
            
             
                for(int i=bottom;i>=top;i--){
                   m[i][left]=c;
                    c++; 
                }
                left++;
            
        }
        return m;
    }
};