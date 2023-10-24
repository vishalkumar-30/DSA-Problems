class Solution {
private:
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    bool isValid(vector<vector<int>>& heights, int mid){
        queue<pair<int, int>> q;
        int r=heights.size(), c=heights[0].size();
        vector<vector<int>>visit(r, vector<int>(c, 0));
        q.push({0, 0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            if(row==r-1 && col==c-1) return true;
            for(auto &d:dir){
                int dr = d[0] + row;
                int dc = d[1] + col;
                if(dr>=0 && dc>=0 && dr<r && dc<c && !visit[dr][dc] && abs(heights[row][col] - heights[dr][dc]) <= mid){
                    visit[dr][dc] = 1;
                    q.push({dr, dc});
                }
            }
        }
        return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0, r=INT_MAX;
        int effort=INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isValid(heights, mid)){
                r=mid-1;
                effort = min(effort, mid);
            }
            else{
                l = mid+1;
            }
        }
        return effort;
    }
};