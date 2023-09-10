class Solution {
public:
    int M = 1e9 +7;
    int helper(int start, int end, int k, vector<vector<int>> &dp){
        if(k==0 && start==end) return 1;
        if(k==0) return 0;
        // if(abs(end-start)>i) return 0;
        if(dp[start+1000][k] != -1) return dp[start+1000][k]%M;
        int left = helper(start-1, end, k-1, dp)%M;
        int right = helper(start+1, end, k-1, dp)%M;

        return dp[start+1000][k] = (left + right)%M;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3001,vector<int>(k+1, -1));
        return helper(startPos, endPos, k, dp);
    }
};