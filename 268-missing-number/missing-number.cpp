class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int total = (n*(n+1))/2;
        // int sum = 0;
        // for(auto it:nums){
        //     sum += it;
        // }
        // return total - sum;
        int x = 0, y=0, i=0;
        for(; i<nums.size(); i++){
            x ^= nums[i];
            y ^= i;
        }
        y ^= i;
        return x^y;
    }
};