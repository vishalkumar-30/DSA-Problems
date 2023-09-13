class Solution {
private:
    int function(int idx, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(idx==0){
            if(target%coins[idx]==0) return target/coins[idx];
            else return 1e9;
        }
        if(dp[target][idx] != 0) return dp[target][idx];
        int notTake = 0 + function(idx-1, target, coins, dp);
        int take = INT_MAX;
        if(coins[idx]<=target) take = 1 + function(idx, target-coins[idx], coins, dp);
        return dp[target][idx] = min(notTake, take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        vector<vector<int>>dp(amount+1, vector<int>(coins.size(), 0));
        ans = function(coins.size()-1, amount, coins, dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};