class Solution {
public:
    int dp[1001][1001];

    int solve(int i, vector<int>&v, int t){
        if(t==0) return 0;
        if(t<0 || i>=v.size()) return INT_MIN;
        if(dp[i][t]!=-1) return dp[i][t];
        int take = 1 + solve(i+1, v, t-v[i]);
        int nottake = solve(i+1, v, t);
        return dp[i][t] = max(take,nottake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, nums, target);
        if(ans <= 0) return -1;
        return ans;
    }
};