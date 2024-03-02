class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0, n = nums.size();
        int end = n-1;
        vector<int> ans(n);
        for(int k = n-1; k>=0; k--){
            int s1 = nums[start]*nums[start];
            int s2 = nums[end]*nums[end];
            if(s1>s2){
                ans[k] = s1;
                start++;
            }
            else {
                ans[k] = s2;
                end--;
            }
        }
        return ans;
    }
};