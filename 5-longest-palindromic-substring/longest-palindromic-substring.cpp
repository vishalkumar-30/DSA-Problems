class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0, n = s.size();
        string res ="";
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int diff=0; diff<n; diff++){
            for(int i=0, j=i+diff; i<n, j<n; i++, j++){
                if(i==j) dp[i][j] = 1;
                else if(diff == 1){
                    if(s[i]==s[j]) dp[i][j] = 2;
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j] = 2+dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){
                    if(diff+1 > maxlen){
                        maxlen = diff+1;
                        res = s.substr(i, diff+1);
                    }
                }
            }
        }
        return res;
    }
};