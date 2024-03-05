class Solution {
private:
    void help(int ind, vector<int> nums, int target, vector<vector<int>>& res, vector<int>sum){
        if(ind == nums.size()){ 
            if(target == 0) res.push_back(sum);
            return;
        }
        
        help(ind+1, nums, target, res, sum);
        if(nums[ind]<=target){
            target = target-nums[ind];
            sum.push_back(nums[ind]);
            help(ind, nums, target, res, sum);
            sum.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>sum;
        help(0, candidates, target, res, sum);
        return res;
    }
};