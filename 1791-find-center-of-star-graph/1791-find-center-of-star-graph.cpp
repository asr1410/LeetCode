class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> map(100001);
        for(int i = 0; i < edges.size(); i++) {
            map[edges[i][0]]++;
            map[edges[i][1]]++;
        }
        int ans = 0;
        for(int i = 0, max = 0; i < 100001; i++) {
            if(max < map[i]) {
                max = map[i];
                ans = i;
            }
        }
        return ans;
    }
};