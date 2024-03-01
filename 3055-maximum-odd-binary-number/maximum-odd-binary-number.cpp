class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1') cnt++;

        }
        string res(n, '0');
        if(cnt >= 1){
            res[n-1] = '1';
            cnt--;
        }
        int i=0;
        while(cnt){
            res[i] = '1';
            cnt--;
            i++;
        }
        return res;
    }
};