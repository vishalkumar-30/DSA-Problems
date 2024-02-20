class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for (vector<int>& it : intervals) {
            if (it[0] <= end) {
                // Merge overlapping intervals
                end = max(end, it[1]);
            } else {
                // Non-overlapping interval found
                res.push_back({start, end});
                start = it[0];
                end = it[1];
            }
        }
        
        // Add the last interval
        res.push_back({start, end});
        
        return res;
    }
};