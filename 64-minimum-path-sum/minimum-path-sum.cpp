class Solution {
private:
    int helper(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(x==0 && y==0) return grid[x][y];
        if(dp[x][y] != -1) return dp[x][y];
        int sum = 1e9;
        if(x>0) sum = grid[x][y] + helper(x-1, y, grid, dp);
        if(y>0){
            int total = grid[x][y] + helper(x, y-1, grid, dp);
            sum = min(sum, total);
        }
        return dp[x][y] = sum;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, grid, dp);
    }
};