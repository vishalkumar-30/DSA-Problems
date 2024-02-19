class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int curr = 0;
        for(int i=0; i<nums.size(); i++){
            if(curr<0){
                curr = nums[i];
            }
            else{
                curr += nums[i];
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};