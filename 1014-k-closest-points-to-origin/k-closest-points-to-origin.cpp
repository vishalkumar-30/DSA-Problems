class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>maxh;
        for(vector<int>& it: points){
            maxh.push({it[0]*it[0] + it[1]*it[1], it});
            if(maxh.size()>k) maxh.pop();
        }
        vector<vector<int>> ans;
        while(maxh.size()>0){
            vector<int>p = maxh.top().second;
            ans.push_back(p);
            maxh.pop();
        }
        return ans;
    }
};