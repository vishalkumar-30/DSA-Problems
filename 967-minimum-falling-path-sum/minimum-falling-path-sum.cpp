class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(j<0 || j>=mat[0].size()) return 1e9;
        if(i==0) return mat[i][j];
        if(dp[i][j] != -101) return dp[i][j];
        int up = mat[i][j] + helper(i-1, j, mat, dp);
        int upLeft = mat[i][j] + helper(i-1, j-1, mat, dp);
        int upRight = mat[i][j] + helper(i-1, j+1, mat, dp);
        return dp[i][j] = min(up, min(upLeft, upRight));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -101));
        int result = 1e9;
        for(int j=0; j<n; j++){
            result = min(result, helper(m-1, j, matrix, dp));
        }
        return result;
    }
};