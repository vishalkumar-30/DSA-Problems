class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_set<int>mp(nums1.begin(), nums1.end());
        for(int it:nums2){
            if(mp.count(it)) res.push_back(it);
            mp.erase(it);
        }
        return res;
    }
};