class Solution {
public:
    int minimumLength(string s) {
        int l=0, r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r] || r==l) return r-l+1;
            if(s[l] == s[r]){
                char t = s[l];
                while(s[l]==t && l<=r) l++;
                while(t==s[r] && l<=r) r--;
            }
        }
        return 0;
    }
};