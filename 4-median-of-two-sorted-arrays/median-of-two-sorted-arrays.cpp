class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        int i=0, j=0;
        int n1 = nums1.size(), n2 = nums2.size();
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]) nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        while(i<n1) nums.push_back(nums1[i++]);
        while(j<n2) nums.push_back(nums2[j++]);
        int n = nums.size();
        if(n%2 == 1) return (double)nums[nums.size()/2];
        int el1 = nums[n/2], el2 = nums[(n/2)-1];
        return (double)(el1 + el2)/2;
    }
};