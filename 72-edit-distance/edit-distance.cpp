class Solution {
public:
    // int helper(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    //     if(i==0) return j;
    //     else if(j==0) return i;
    //     if(dp[i-1][j-1] != -1) return dp[i-1][j-1];
    //     if(s1[i-1] == s2[j-1]) return dp[i-1][j-1]=helper(i-1, j-1, s1, s2, dp);
    //     else return dp[i-1][j-1]=min(
    //         1 + helper(i-1, j, s1, s2, dp),   //deletion
    //         min(1 + helper(i, j-1, s1, s2, dp),   //replace
    //         1 + helper(i-1, j-1, s1, s2, dp))  //Insert
    //     );
    // }
    int minDistance(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<int>prev(n2+1, 0), curr(n2 +1, 0);
        // for(int i=0; i<=n1; i++) dp[i][0] = i;
        for(int j=0; j<=n2; j++) prev[j] = j;

        for(int i=1; i<=n1; i++){
            curr[0]=i;
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1]) curr[j]=prev[j-1];
                else curr[j]=min(
                    1 + prev[j],   //deletion
                    min(1 + curr[j-1],   //replace
                    1 + prev[j-1])  //Insert
                );
            }
            prev = curr;
        }

        return prev[n2];
    }
};