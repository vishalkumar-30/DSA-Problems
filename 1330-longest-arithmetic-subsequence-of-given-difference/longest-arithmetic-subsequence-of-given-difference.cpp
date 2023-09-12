class Solution {
// private:
//     int solve(int ind, int prev, int diff, vector<int> &nums, vector<vector<int>> &dp){
//         if(ind == nums.size()) return 0;
//         if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
//         int notTake = solve(ind+1, prev, diff, nums, dp);
//         int take = 0;
//         if(prev == -1 || nums[ind]-nums[prev] == diff){
//             take = 1 + solve(ind + 1, ind, diff, nums, dp);
//         }
//         return dp[ind][prev+1]=max(take, notTake);
//     }
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int ans = 1;
        for(int a : arr){
            int prev = dp.count(a-difference)?dp[a-difference]:0;
            dp[a] = prev+1;
            ans = max(ans, dp[a]);
        }
        return ans;
    }
};