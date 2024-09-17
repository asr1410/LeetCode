class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& price, vector<int>& start, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans,res;
        vector<vector<bool>>seen(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        vector<vector<int>>dirs={{-1,0},{0,-1},{0,1},{1,0}};
        // distance
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto p=q.front();
                    q.pop();
                if(seen[p.first][p.second])
                    continue;
                if(grid[p.first][p.second]==0)
                    continue;
                seen[p.first][p.second]=true;
                if(grid[p.first][p.second]!=1){
                    int val=grid[p.first][p.second];
                    if(val>=price[0] && val<=price[1])
                       res.push_back({dist,val,p.first,p.second});
                }
                for(auto & dir:dirs){
                    int row=p.first+dir[0],col=dir[1]+p.second;
                    if(row>=0 && row<m && col>=0 && col<n)
                        q.push({row,col});
                }      
            }
            dist++;
        }
        sort(res.begin(),res.end());
        for(int i=0;i<min(int(k),int(res.size()));i++)
            ans.push_back({res[i][2],res[i][3]});
        return ans;
        
    }
};