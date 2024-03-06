class Solution {
public:
    void help(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, vector<int>& used){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            used[i]=1;
            temp.push_back(nums[i]);
            
            help(nums, res, temp, used);
            used[i]=0;
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        help(nums, res, temp, used);
        return res;
    }
};