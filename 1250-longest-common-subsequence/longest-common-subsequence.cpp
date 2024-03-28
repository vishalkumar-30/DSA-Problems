class Solution {
public:
    int helper(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp){
        if(ind1==0 || ind2==0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int len1 = 0;
        if(s1[ind1] == s2[ind2]) {
            len1 = 1 + helper(ind1-1, ind2-1, s1, s2, dp);
        }
        int len2 = 0;
        len2 = max(helper(ind1-1, ind2, s1, s2, dp), helper(ind1, ind2-1, s1, s2, dp));
        return dp[ind1][ind2] = max(len1, len2);
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        for(int ind1=1; ind1<=n1; ind1++){
            for(int ind2=1; ind2<=n2; ind2++){
                int len1 = 0;
                if(s1[ind1-1] == s2[ind2-1]) {
                    len1 = 1 + dp[ind1-1][ind2-1];
                }
                int len2 = 0;
                len2 = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
                dp[ind1][ind2] = max(len1, len2);
            }
        }
        return dp[n1][n2];
    }
};