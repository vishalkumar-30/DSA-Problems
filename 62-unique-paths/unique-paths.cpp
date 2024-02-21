
class Solution {
/*
private:
    int helper(int i, int j, vector<vector<int>>&dp){
        if(i==0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = helper(i-1, j, dp);
        int left = helper(i, j-1, dp);
        return dp[i][j]=up+left;
    }
*/

public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        vector<int>prev(m, 0);
        
        for(int i=0; i<m; i++){
            vector<int>curr(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int up = 0, down = 0;
                    if(i>0) up = prev[j];
                    if(j>0) down = curr[j-1];
                    curr[j] = up + down;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
