class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int left = 0;
        long long count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]) left = i;
            count += i-left+1;
        }
        return count;
    }
};