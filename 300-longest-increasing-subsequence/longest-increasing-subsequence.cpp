class Solution {
public:
int helper(int ind, int prevInd, vector<int>&nums, vector<vector<int>> &dp){
    if(ind == nums.size()) return 0;
    if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
    int len = 0 + helper(ind + 1, prevInd, nums, dp);
    if(prevInd == -1 || nums[ind] > nums[prevInd]){
        len = max(len, 1+helper(ind+1, ind, nums, dp));
    }
    return dp[ind][prevInd+1] = len;
}
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int previndx = -1;
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return helper(0, -1, nums, dp);
    }
};