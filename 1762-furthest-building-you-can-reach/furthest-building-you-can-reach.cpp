class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        if(heights.size() == 1) return 0;
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i=0; i<heights.size()-1; i++){
            int diff = heights[i+1] - heights[i];
            if(diff > 0) minh.push(diff);
            if(minh.size() > ladders){
                bricks -= minh.top();
                minh.pop();
            }
            if(bricks<0) return i;
            ans = i;
        }
        return ans+1;
    }
};
