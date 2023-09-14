class Solution {
private:
    int f(int i, int j, int k, vector<vector<int>>& grid, vector<vector<int>> &vis, vector<vector<vector<int>>>&dp){
        if(i==0 && j==0) dp[i][j][k]=0;

        if(i<0 || j<0|| i>=grid.size() || j>=grid[0].size() || vis[i][j]) return 1e6;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        if(grid[i][j]==1){
            if(k==0) return 1e6;
            else k--;
        }

        vis[i][j]=1;
        int top = 1+f(i-1, j,k,grid,vis, dp);
        int left =1+f(i, j-1,k,grid,vis, dp);
        int down =1+f(i+1, j,k,grid,vis, dp);
        int right = 1+f(i, j+1,k,grid,vis, dp);
    
        vis[i][j] = 0;

        return dp[i][j][k] = min({top, left, down, right});
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m=grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = f(n-1, m-1, k, grid, vis, dp);
        return ans > n*m ? -1 : ans;
    }
};