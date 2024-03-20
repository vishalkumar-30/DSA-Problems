class Solution {
public:
    int helper(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i<0) return j+1;
        else if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j]=helper(i-1, j-1, s1, s2, dp);
        else return dp[i][j]=min(
            1 + helper(i-1, j, s1, s2, dp),   //deletion
            min(1 + helper(i, j-1, s1, s2, dp),   //replace
            1 + helper(i-1, j-1, s1, s2, dp))  //Insert
        );
    }
    int minDistance(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return helper(n1-1, n2-1, s1, s2, dp);
    }
};