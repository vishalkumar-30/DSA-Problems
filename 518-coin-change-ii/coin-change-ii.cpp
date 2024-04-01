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
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return helper(n-1, coins, amount, dp);
    }
};