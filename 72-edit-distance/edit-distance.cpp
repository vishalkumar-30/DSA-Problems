class Solution {
public:
    int helper(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i==0) return j;
        else if(j==0) return i;
        if(dp[i-1][j-1] != -1) return dp[i-1][j-1];
        if(s1[i-1] == s2[j-1]) return dp[i-1][j-1]=helper(i-1, j-1, s1, s2, dp);
        else return dp[i-1][j-1]=min(
            1 + helper(i-1, j, s1, s2, dp),   //deletion
            min(1 + helper(i, j-1, s1, s2, dp),   //replace
            1 + helper(i-1, j-1, s1, s2, dp))  //Insert
        );
    }
    int minDistance(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        for(int i=0; i<=n1; i++) dp[i][0] = i;
        for(int j=0; j<=n2; j++) dp[0][j] = j;

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(
                    1 + dp[i-1][j],   //deletion
                    min(1 + dp[i][j-1],   //replace
                    1 + dp[i-1][j-1])  //Insert
                );
            }
        }

        return dp[n1][n2];
    }
};