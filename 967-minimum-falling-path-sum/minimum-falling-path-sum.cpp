class Solution {
// private:
//     int helper(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
//         if(j<0 || j>=mat[0].size()) return 1e9;
//         if(i==0) return mat[i][j];
//         if(dp[i][j] != -101) return dp[i][j];
//         int up = mat[i][j] + helper(i-1, j, mat, dp);
//         int upLeft = mat[i][j] + helper(i-1, j-1, mat, dp);
//         int upRight = mat[i][j] + helper(i-1, j+1, mat, dp);
//         return dp[i][j] = min(up, min(upLeft, upRight));
//     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for(int j=0; j<n; j++) prev[j] = matrix[0][j];

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + prev[j];
                int upL = 1e9;
                if(j-1>=0) upL = matrix[i][j] + prev[j-1];
                int upR = 1e9;
                if(j+1 <n) upR = matrix[i][j] + prev[j+1];
                curr[j] = min(up, min(upL, upR));
            }
            prev = curr;
        }
        
        int result = 1e9;
        for(int j=0; j<n; j++){
            
            result = min(result, prev[j]);
        }
        return result;
    }
};