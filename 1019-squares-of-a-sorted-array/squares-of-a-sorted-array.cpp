class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=n-1;
        vector<int>ans(n);
        for(int k=n-1; k>=0; k--){
            int com1 = nums[i]*nums[i];
            int com2 = nums[j]*nums[j];

            if(com1>com2){
                ans[k]=com1;
                i++;
            }
            else{
                ans[k]=com2;
                j--;
            }
        }
        return ans;
    }
};