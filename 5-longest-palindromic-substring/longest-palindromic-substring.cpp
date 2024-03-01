class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        string ans;
        int mxlen = 1;
        int start=0, end = 0;

        for(int i=0; i<n; i++){
            dp[i][i]=1;
            for(int j=0; j<i; ++j){
                if(s[j] == s[i] && (i-j <= 2 || dp[j+1][i-1])) {
                    dp[j][i] = 1;
                    if(i-j+1>mxlen){
                        mxlen = i-j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};