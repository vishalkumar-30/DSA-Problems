class Solution {
public:
int sumdigit(int n){
    int ans = 0;
    while(n){
        ans += n%10;
        n /= 10;
    }
    return ans;
}
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = sumdigit(x);
        if(x%sum == 0) return sum;
        else return -1;
    }
};