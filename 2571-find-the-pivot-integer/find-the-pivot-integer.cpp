class Solution {
public:
    int pivotInteger(int n) {
        int low = 0;
        long high = n;
        long sum = (n*(n+1))/2;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long half = (mid*(mid+1))/2;
            long long temp = sum - half + mid;
            if(half == temp) return mid;
            if(half<temp) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};