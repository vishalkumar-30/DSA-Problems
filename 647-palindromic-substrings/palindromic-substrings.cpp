class Solution {
public:
    int countSubstrings(string s) {
        int count=0, n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<s.size(); ++i){
            for(int j=i; j<s.size(); j++){
                count += solve(dp, s, i, j);
            }
        }
        return count;
    }
    int solve(vector<vector<int>>& dp, string s, int i, int j){
        if(i>=j) return 1;
        if(dp[i][j] >= 0) return dp[i][j];
        return dp[i][j] = s[i] == s[j] ? solve(dp, s, i+1, j-1):0;
    }
};