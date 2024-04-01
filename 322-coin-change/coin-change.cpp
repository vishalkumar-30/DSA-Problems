class Solution {
public:
    int helper(vector<int>& coins, int target, int ind, vector<vector<int>>& dp){
        if(ind == 0){
            if(target%coins[ind] == 0) return target/coins[ind];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nT = helper(coins, target, ind-1, dp);
        int T = INT_MAX;
        if(coins[ind]<=target) T = 1 + helper(coins, target-coins[ind], ind, dp);
        return dp[ind][target] = min(nT, T);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        ans = helper(coins, amount, n-1, dp);
        if(ans == 1e9 ) return -1;
        return ans;
    }
};