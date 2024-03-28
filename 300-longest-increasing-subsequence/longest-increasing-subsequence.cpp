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
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(0, -1, nums, dp);
    }
};