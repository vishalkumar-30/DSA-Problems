class Solution {
    int helper(int i, int j, int prev, vector<int>& nums, vector<vector<int>>&dp) {
        if (i == j || i > j) return 0; 
        if(dp[i][j] != -1) return dp[i][j];
        // First two
        int cnt1 = 0;
        if (j - i >= 2 && nums[i] + nums[i + 1] == prev) {
            cnt1 = 1 + helper(i + 2, j, prev, nums, dp);
        }
        // Last two
        int cnt2 = 0;
        if (j - i >= 2 && nums[j] + nums[j - 1] == prev) {
            cnt2 = 1 + helper(i, j - 2, prev, nums, dp);
        }
        // First & last
        int cnt3 = 0;
        if (i < j && nums[i] + nums[j] == prev) {
            cnt3 = 1 + helper(i + 1, j - 1, prev, nums, dp);
        }
        return dp[i][j]=max(cnt1, max(cnt2, cnt3));
    }

public:
    int maxOperations(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, n=nums.size();
        vector<vector<int>>dp1(n, vector<int>(n, -1));
        vector<vector<int>>dp2(n, vector<int>(n, -1));
        vector<vector<int>>dp3(n, vector<int>(n, -1));
        int prev1 = nums[i] + nums[i + 1];
        int cnt1 = helper(i + 2, j, prev1, nums, dp1);

        int prev2 = nums[j] + nums[j - 1];
        int cnt2 = helper(i, j - 2, prev2, nums, dp2);

        int prev3 = nums[i] + nums[j];
        int cnt3 = helper(i + 1, j - 1, prev3, nums, dp3);

        return max(cnt1, max(cnt2, cnt3))+1;
    }
};