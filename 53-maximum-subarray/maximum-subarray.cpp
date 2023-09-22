class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax=0;   //train 1
        int maxi=INT_MIN;  // train 2
// ab ye train me bogi purani judna chahti hai ya phir nayi bogi
        for(int i=0; i<nums.size(); i++){
            if(currMax<0){
                currMax = nums[i];
            }
            else{
                currMax += nums[i];
            }
            maxi = max(maxi, currMax);
        }
        return maxi;
    }
};