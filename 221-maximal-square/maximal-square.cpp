class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>>ans(m, vector<int>(n, 0));
        int res=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0){
                    if(matrix[i][j] == '1') ans[i][j] = 1;
                } 
                else {
                    if(matrix[i][j]=='1') ans[i][j] = 1 + min(ans[i-1][j], min(ans[i-1][j-1], ans[i][j-1])) ;
                }
                res = max(res, ans[i][j]); 
            }
        }
        return res*res;
    }
};