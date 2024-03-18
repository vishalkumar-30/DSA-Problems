class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pro = INT_MIN, suffix =1, prefix=1;
        for(int i = 0; i < n; i++){
            if(suffix == 0) suffix = 1;
            if(prefix == 0) prefix = 1;
            suffix *= nums[i];
            prefix *= nums[n-1-i];
            pro = max(pro, max(suffix, prefix));
        }
        return pro;
    }
};
