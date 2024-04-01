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
        int t = sum/2;
        vector<vector<int>>dp(n, vector<int>(t+1, false));

        for(int ind=0; ind<nums.size(); ind++) dp[ind][0] = true;
        for(int target = 0; target<=t; target++) {
            if(nums[0] == target) dp[0][target] = true;
        }

        for(int ind=1; ind<nums.size(); ind++){
            for(int target=0; target<=t; target++){
                bool nP = dp[ind-1][target];
                bool P = false;
                if(nums[ind] <= target) P = dp[ind-1][target-nums[ind]];
                dp[ind][target]=nP || P;
            }
        }

        return dp[n-1][t];
    }
};