class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1, n = points.size(), minEnd = INT_MAX;
        sort(points.begin(), points.end());
        if(n==1) return ans;
        sort(points.begin(), points.end());
        for(auto& p: points) {
            if(p[0] > minEnd) {
                ans++; minEnd = p[1];
            }
            else minEnd = min(minEnd, p[1]);
        }
        return ans;
    }
};