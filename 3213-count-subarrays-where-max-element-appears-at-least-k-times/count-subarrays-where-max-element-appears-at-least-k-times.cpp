class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int cnt=0, i=0, j=0, maxe=-1;
        for(auto it:nums) maxe = max(maxe, it);
        
        for(; i<nums.size(); i++){
            if(nums[i]==maxe) cnt++;
            while(j<=i && cnt>=k){
                ans += nums.size()-i;
                if(nums[j]==maxe) cnt--;
                j++;
            }
        }
        return ans;
    }
};