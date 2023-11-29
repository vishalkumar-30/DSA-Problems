class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int totalSum=0;
        vector<int>ans;
        for(auto it: nums) totalSum += it;
        int leftSum=0;
        for(int i=0; i<nums.size(); i++){
            int temp = ((nums[i]*i)-leftSum) + ((totalSum-leftSum)-(nums[i]*(nums.size()-i)));
            ans.push_back(temp);
            leftSum += nums[i];
        }
        return ans;
    }
};