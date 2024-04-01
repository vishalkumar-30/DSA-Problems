class Solution {
private:
    bool helper(int ind, vector<int> &nums, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return (target == nums[0]);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool nP = helper(ind-1, nums, target, dp);
        bool P = false;
        if(nums[ind] <= target) P = helper(ind-1, nums, target-nums[ind], dp);
        return dp[ind][target]=nP || P;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i:nums){
            sum += i;
        }
        if(sum%2 != 0) return false;
        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return helper(n-1, nums, target, dp);
    }
};