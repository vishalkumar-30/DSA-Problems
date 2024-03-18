class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pro = INT_MIN;
        for(int i = 0; i < n; i++){
            int p = 1;
            for(int j = i; j < n; j++){
                p *= nums[j];
                pro = max(pro, p);
            }
        }
        return pro;
    }
};
