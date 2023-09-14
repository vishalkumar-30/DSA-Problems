class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int ans=-1, n=0, dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
        queue<array<int, 3>> q;
        q.push({0, 0, k});
        while(!q.empty()){
            if(n-- == 0){
                ans++;
                n = q.size()-1;
            }
            auto [x, y, obj] = q.front();
            q.pop();
            if(x+1 == grid.size() && y+1 == grid[0].size()) return ans;
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()) continue;
            obj -= grid[x][y];
            if(vis[x][y] >= obj) continue;
            vis[x][y] = obj;
            for(auto d:dir) q.push({x+d[0], y+d[1], obj});
        }
        return -1;
    }
};