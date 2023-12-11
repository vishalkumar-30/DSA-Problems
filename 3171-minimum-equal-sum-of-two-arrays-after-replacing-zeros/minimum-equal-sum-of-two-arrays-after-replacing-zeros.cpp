class Solution {
public:
    #define ll long long
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1=0, s2=0, c1=0, c2=0;
        for(int it:nums1){
            s1 += it;
            c1 += (it==0);
        }
        for(int it:nums2){
            s2 += it;
            c2 += (it==0);
        }
        if(c1==0 && s1<s2+c2) return -1;
        if(c2==0 && s2<s1+c1) return -1;
        return max(s1+c1, s2+c2);
    }
};