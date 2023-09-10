class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int Gcd = __gcd(targetX, targetY);
        return (Gcd & (Gcd-1))==0;
    }
};