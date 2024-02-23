class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort (nums.begin(), nums.end());
        vector<vector<int>>res;
        if(nums.size()==0) return res;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long target2 = (long)(target-nums[i])-nums[j];
                long low = j+1;
                long high = n-1;
                while(low<high){
                    long twosum = nums[low] + nums[high];
                    if(twosum>target2) high--;
                    else if(twosum<target2) low++;
                    else{
                        vector<int> ans(4, 0);
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2] = nums[low];
                        ans[3] = nums[high];
                        res.push_back(ans);
                        while(low<high && nums[low]==ans[2]) low++;
                        while(high>low && nums[high]==ans[3]) high--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1])j++;
            }
            while(i+1<n && nums[i]==nums[i+1])i++;
        }
        return res;
    }
};