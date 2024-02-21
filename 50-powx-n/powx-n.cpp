class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long p=n;
        if(n<0) p = p*(-1);
        while(p){
            if(p%2){
                ans = ans * x;
                p = p - 1;
            }
            else {
                p = p/2;
                x *= x;
            }
        }
        if(n<0) ans = (double)1/(double)ans;
        return ans;  
    }
};