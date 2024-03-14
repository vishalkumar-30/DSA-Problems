class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int res=0, n = nums.size();
        // int l=0, r=0, sum=0;
        // while(r<n ){
        //     if(sum == goal){
        //         res++;
                
        //     }
            
        //     if(r<n && sum<=goal){
        //         sum += nums[r]; 
        //         if(sum == goal) res++;
        //         r++;
        //     }
        //     else if(sum>goal && l<r){
        //         sum -= nums[l];
        //         if(sum == goal) res++;
        //         l++;
        //     }
        // }
        // return res;
        unordered_map<int, int>mp;
        int sum = 0, res = 0, n=nums.size();
        mp[0] = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int target = sum-goal;
            if(mp[target]){
                res += mp[target];
            }
            mp[sum]++;
        }
        return res;
    }
};