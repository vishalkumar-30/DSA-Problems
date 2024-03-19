class Solution { // Here are we are doing tabulation by shifting the index
public:
    // int helper(int ind1, int ind2, string &text1, string &text2, vector<vector<int>>& dp){
    //     if(ind1<0 || ind2<0) return 0;
    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     if(text1[ind1] == text2[ind2]){
    //         return dp[ind1][ind2]=1+helper(ind1-1, ind2-1, text1, text2, dp);
    //     }
    //     else{
    //         return dp[ind1][ind2]=max(helper(ind1-1, ind2, text1, text2, dp), 
    //         helper(ind1, ind2-1, text1, text2, dp));
    //     }
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        for(int ind1=1; ind1<=n1; ind1++){
            for(int ind2=1; ind2<=n2; ind2++){
                if(text1[ind1-1] == text2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};