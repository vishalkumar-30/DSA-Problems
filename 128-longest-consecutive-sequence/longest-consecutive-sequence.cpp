class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        int ans=0;
        for(auto it:nums) mp.insert(it);
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]-1) == mp.end()){
                int cnt = 1;
                int n = nums[i];
                while(mp.find(n+1) != mp.end()){
                    n += 1;
                    cnt += 1;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};