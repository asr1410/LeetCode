class Solution {
public:
    void dfs(int room, vector<int>& vis, vector<int>& keys, vector<vector<int>>& rooms) {
        vis[room] = 1;
        for(auto& key : rooms[room]) {
            keys[key] = 1;
        }
        for(auto& key : rooms[room]) {
            if(keys[key] == 1 and vis[key] == 0) {
                dfs(key, vis, keys, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> key(n, 0);
        key[0] = 1;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0 and key[i] == 1) {
                dfs(i, vis, key, rooms);
            }
        }
        for(int i = 0; i < n; i++) {
            if(key[i] == 0) {
                return false;
            }
        }
        return true;
    }
};