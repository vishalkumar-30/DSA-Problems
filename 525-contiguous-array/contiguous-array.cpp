class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mp;
        mp[0] = -1;
        int res=0, n=nums.size(), sum=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1) sum += nums[i];
            else sum -= 1;
            if(mp.find(sum) !=mp.end()){
                res = max(res, i - mp[sum] );
            }
            else mp[sum] = i;
        }
        return res;
    }
};