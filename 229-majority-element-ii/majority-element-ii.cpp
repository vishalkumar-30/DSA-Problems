class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int val1 = 0, val2 = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        
        // Step 1: Find two potential candidates
        for (int i = 0; i < n; i++) {
            if (val1 == nums[i]) {
                cnt1++;
            } else if (val2 == nums[i]) {
                cnt2++;
            } else if (cnt1 == 0) {
                val1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                val2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        // Step 2: Count the occurrences of the potential candidates
        cnt1 = cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val1) {
                cnt1++;
            } else if (nums[i] == val2) {
                cnt2++;
            }
        }
        
        // Step 3: Check if the candidates are majority elements
        if (cnt1 > n / 3) {
            ans.push_back(val1);
        }
        if (cnt2 > n / 3) {
            ans.push_back(val2);
        }
        
        return ans;
    }
};
