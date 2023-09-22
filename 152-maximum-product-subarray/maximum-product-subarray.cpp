class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suffix = INT_MIN, preffix = INT_MIN;
        if(nums.size() == 1) return nums[0];
        int low = 1, high = 1;
        for(int i=0; i<nums.size(); i++){
            if(low==0){
                low=nums[i];
            }
            else low *= nums[i];
            suffix = max(suffix, low);
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(high==0){
                high=nums[i];
            }
            else high *= nums[i];
            preffix = max(preffix, high);
        }
        return max(suffix, preffix);
    }
};