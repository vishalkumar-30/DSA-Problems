class Solution {
public:
    int countSubstrings(string s) {
        int count=0, n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = s.size() - 1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (i + 1 == j) {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : 0;
                }
                count += dp[i][j];
            }
        }
        return count;
    }
    // int solve(vector<vector<int>>& dp, string s, int i, int j){
    //     if(i>=j) return 1;
    //     if(dp[i][j] >= 0) return dp[i][j];
    //     return dp[i][j] = s[i] == s[j] ? solve(dp, s, i+1, j-1):0;
    // }
};