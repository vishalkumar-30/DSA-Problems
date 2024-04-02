class Solution {
public:
int helper(int ind, int prevind, vector<int> &nums, vector<vector<int>>&dp){
    if(ind == nums.size()) return 0;
    if(dp[ind][prevind+1] != -1) return dp[ind][prevind+1];
    int len = 0;
    if(prevind==-1 || nums[ind] > nums[prevind]){
        len = 1 + helper(ind+1, ind, nums, dp);
    }
    return dp[ind][prevind+1] = max(len, helper(ind+1, prevind, nums, dp));

}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi=-1;
        vector<int> dp(n, 1);
        for(int i=0; i<nums.size(); i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev]<nums[i]) dp[i] = max(dp[i], dp[prev]+1);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};