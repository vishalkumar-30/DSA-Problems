class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = INT_MIN, suf = INT_MIN;
        int p = 1;
        for(int i=0; i<nums.size(); i++){
            if(p==0) p=1;
            p *= nums[i];
            pre = max(pre, p);
        }
        p=1;
        for(int i=nums.size()-1; i>=0; i--){
            if(p==0) p=1;
            p *= nums[i];
            suf = max(suf, p);
        }
        return max(suf, pre);
    }
};