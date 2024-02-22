class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int bkt = 1;
        for(int i=1; i<nums.size(); i++){
            if(bkt==0){
                bkt = 1;
                val = nums[i];
            }
            else{
                if(nums[i] == val) bkt++;
                else bkt--;
            }
        }
        return val;
    }
};