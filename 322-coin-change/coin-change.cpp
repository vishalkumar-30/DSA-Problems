class Solution {
// private:
//     int function(int idx, int target, vector<int> &coins, vector<vector<int>> &dp){
//         if(idx==0){
//             if(target%coins[idx]==0) return target/coins[idx];
//             else return 1e9;
//         }
//         if(dp[target][idx] != 0) return dp[target][idx];
//         int notTake = 0 + function(idx-1, target, coins, dp);
//         int take = INT_MAX;
//         if(coins[idx]<=target) take = 1 + function(idx, target-coins[idx], coins, dp);
//         return dp[target][idx] = min(notTake, take);
//     }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        int n = coins.size();
        vector<vector<int>>dp(amount+1, vector<int>(n, 0));
        for(int t=0; t<=amount; t++){
            if(t%coins[0]==0) dp[t][0] = t/coins[0];
            else dp[t][0]=1e9;
        }
        for(int idx=1; idx<n; idx++){
            for(int target=0; target<=amount; target++){
                int notTake = 0 + dp[target][idx-1];
                int take = INT_MAX;
                if(coins[idx]<=target) take = 1 + dp[target-coins[idx]][idx];
                dp[target][idx] = min(notTake, take);
            }
        }
        ans = dp[amount][n-1];
        if(ans>=1e9) return -1;
        return ans;
    }
};