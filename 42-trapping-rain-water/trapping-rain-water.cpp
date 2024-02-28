class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        int temp = height[0];
        suffix[0] = height[0];
        for(int i=1; i<n; i++){
             temp = max(temp, height[i]);
            suffix[i] = temp;
        }
        temp = height[n-1];
        prefix[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            temp = max(temp, height[i]);
            prefix[i] = temp;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += min(suffix[i], prefix[i]) - height[i];
        }
        return ans;
    }
};
