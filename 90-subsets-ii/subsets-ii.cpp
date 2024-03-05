class Solution {
private:
    void helper(vector<int>nums, vector<int>&res, vector<vector<int>>&ans, int i){
        ans.push_back(res);
        for(int ind = i; ind<nums.size(); ind++){
            if(ind!=i && nums[ind]==nums[ind-1]) continue;
            res.push_back(nums[ind]);
            helper(nums, res, ans, ind+1);
            res.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        vector<vector<int>>ans;
        helper(nums, res, ans, 0);
        return ans;
    }
};