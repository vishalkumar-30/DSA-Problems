class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0 ) return false;
        long long x = n & n-1;
        if(x==0) return 1;
        else return 0;
    }
};