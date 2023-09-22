class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];   //ye hai hamara bucket 
        int count = 1;    // isme bande ki counting hogi
        for(int i=1; i<nums.size(); i++){
            if(count==0){
                count=1;
                val = nums[i];
            }
            else if(nums[i]==val) count++;
            else count --;
        }
        return val;
    }
};