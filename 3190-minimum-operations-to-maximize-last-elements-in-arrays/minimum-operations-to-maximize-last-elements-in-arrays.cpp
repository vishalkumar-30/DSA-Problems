class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m1=nums1[n-1];
        int m2=nums2[n-1];
        int c1=0, c2=1, f1=1, f2=1;
        for(int i=0; i<n-1; i++){
            if(nums1[i]<=m1 && nums2[i]<=m2) continue;
            else if(nums1[i]<=m2 && nums2[i]<=m1) c1++;
            else f1=0;
        }
        m1 = m2;
        m2 = nums1[n-1];
        for(int i=0; i<n-1; i++){
            if(nums1[i]<=m1 && nums2[i]<=m2) continue;
            else if(nums1[i]<=m2 && nums2[i]<=m1) c2++;
            else f2=0;
        }
        if(f1 || f2) return min(c1, c2);
        return -1;
    }
};