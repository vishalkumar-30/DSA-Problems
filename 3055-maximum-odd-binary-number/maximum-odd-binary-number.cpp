class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0, zero=0;
        for(int it : s){
            if(it == '1')one++;
            else zero++;

        }
        s="";
        for(int i=1; i<one; i++) s += '1';
        for(int i=0; i<zero; i++) s+='0';
        s += '1';
        return s;
    }
};