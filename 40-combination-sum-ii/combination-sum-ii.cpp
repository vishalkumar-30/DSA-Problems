class Solution {
public:
void help(int ind, vector<int>&nums, int target, vector<vector<int>>&res, vector<int>&temp){
    if(target == 0){
        res.push_back(temp);
        return;
    }
    for(int i=ind; i<nums.size(); i++){
        if(i>ind && nums[i] == nums[i-1]) continue;
        if(nums[i]>target) break;
        // target = target - nums[i];
        temp.push_back(nums[i]);
        help(i+1, nums, target - nums[i], res, temp);
        temp.pop_back();
    }
    return;
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        help(0, candidates, target, res, ans);
        return res;
    }
};