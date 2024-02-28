class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, n=height.size();
        int right = n-1;
        int leftbar = height[0], rightbar = height[n-1];
        long long ans=0;
        while(left<=right){
            if(leftbar < rightbar){
                if(leftbar<height[left]){
                    leftbar = height[left];
                }
                else{
                    ans += leftbar-height[left];
                    left++;
                }
            }
            else {
                if(rightbar<height[right]){
                    rightbar = height[right];
                }
                else{
                    ans += rightbar-height[right];
                    right--;
                }
            }
        }
        return ans;
    }
};