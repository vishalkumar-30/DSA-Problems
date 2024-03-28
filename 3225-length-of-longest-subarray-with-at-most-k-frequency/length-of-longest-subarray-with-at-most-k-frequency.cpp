class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int i=0, j=0, ans=0;
        for(; i<nums.size(); i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans, (i-j+1));
        }
        return ans;
    }
};