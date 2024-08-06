class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        for(int i = 0, j = 1; j < edges.size(); i++, j++) {
            if(edges[i][0] == edges[j][0]) {
                return edges[i][0];
            } else if(edges[i][1] == edges[j][1]) {
                return edges[i][1];
            } else if(edges[i][0] == edges[j][1]) {
                return edges[i][0];
            } else if(edges[i][1] == edges[j][0]) {
                return edges[i][1];
            }
        }
        return -1;
    }
};