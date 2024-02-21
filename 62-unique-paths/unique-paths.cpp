class Solution {
    int helper(int i, int j, vector<vector<int>>&pat){
        int m = pat.size(), n = pat[0].size();
        if(i == m-1 && j == n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(pat[i][j] != -1) return pat[i][j];
        int down = helper(i+1, j, pat);
        int rt = helper(i, j+1, pat);
        return pat[i][j] = down + rt;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>pat(m, vector<int>(n, -1));
        return helper(0, 0, pat);
    }
};