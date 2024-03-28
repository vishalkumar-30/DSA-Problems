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
        vector<int> next(n+1, 0), curr(n+1, 0);
        for(int ind = n-1; ind>=0; ind--){
            for(int prevind = n-1; prevind>=-1; prevind--){
                int len = 0;
                if(prevind==-1 || nums[ind] > nums[prevind]){
                    len = 1 + next[ind+1];
                }
                curr[prevind+1] = max(len, next[prevind+1]);
            }
            next = curr;
        }
        return next[-1+1];
    }
};