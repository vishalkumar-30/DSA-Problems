class Solution {
    // vector<int> dp;
    // int help(int i, string s){
    //     if(i>=s.size()) return 1;
    //     else if(s[i]=='0') return 0;
    //     else if(i==s.size()-1) return 1;
    //     else if(dp[i]!=-1) return dp[i];
    //     else if(s[i]=='1' || (s[i]=='2' && (s[i+1]>='0'&& s[i+1]<='6')))
    //         return dp[i]=help(i+1, s) + help(i+2, s);
    //     else return dp[i]=help(i+1, s);
    // }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(s.size()+1);
        if(s.size()==0 || s[0]=='0')return 0;
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            if(s[i-1] != '0') dp[i]=dp[i-1];
            if(s[i-2]=='1')dp[i] += dp[i-2];
            else if(s[i-2]=='2' && (s[i-1]>='0' && s[i-1]<='6')) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};