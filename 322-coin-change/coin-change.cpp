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
        for(int t=0; t<=amount; t++){
            if(t%coins[0] == 0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }
        for(int ind=1; ind<coins.size(); ind++){
            for(int t=0; t<=amount; t++){
                int notTake = dp[ind-1][t];
                int take = INT_MAX;
                if(coins[ind]<=t) take = 1 + dp[ind][t-coins[ind]];
                dp[ind][t] = min(notTake, take);
            }
        }
        ans = dp[coins.size()-1][amount];
        if(ans == 1e9 ) return -1;
        return ans;
    }
};