class Solution {
public:
// This is anothewr tabulation
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        vector<int>dp(n, 1);

        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(nums[ind]>nums[prev]){
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        return maxi;
    }
};