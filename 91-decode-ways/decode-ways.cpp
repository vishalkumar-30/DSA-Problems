class Solution {
    vector<int> dp;
    int help(int i, string s){
        if(i>=s.size()) return 1;
        else if(s[i]=='0') return 0;
        else if(i==s.size()-1) return 1;
        else if(dp[i]!=-1) return dp[i];
        else if(s[i]=='1' || (s[i]=='2' && (s[i+1]>='0'&& s[i+1]<='6')))
            return dp[i]=help(i+1, s) + help(i+2, s);
        else return dp[i]=help(i+1, s);
    }
public:
    int numDecodings(string s) {
        dp.resize(s.length());
        dp.assign(s.length(), -1);
        return help(0, s);
    }
};