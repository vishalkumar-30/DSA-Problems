class Solution {
    int helper(int ind, vector<int>&coins, int amount, vector<vector<int>> &dp){
        if(ind == 0){
            return (amount%coins[ind] == 0);
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int nT = helper(ind-1, coins, amount, dp);
        int T = 0;
        if(coins[ind] <= amount){
            T = helper(ind, coins, amount-coins[ind], dp);
        }
        return dp[ind][amount] = T+nT;
    }
public:
    int change(int amp, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amp+1, 0));

        for(int i=0; i<=amp; i++) {
            if(i%coins[0] == 0) dp[0][i] = 1;
        }
        for(int ind=1; ind<n; ind++){
            for(int amount=0; amount<=amp; amount++){
                int nT = dp[ind-1][amount];
                int T = 0;
                if(coins[ind] <= amount){
                    T = dp[ind][amount-coins[ind]];
                }
                dp[ind][amount] = T+nT;
            }
        }
        return dp[n-1][amp];
    }
};