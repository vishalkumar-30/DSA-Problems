//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visit){
        int m=grid.size();
        int n=grid[0].size();
        visit[i][j]=1;
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int x=-1; x<=1; x++){
                for(int y=-1; y<=1; y++){
                    int nrow=row+x;
                    int ncol=col+y;
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visit[nrow][ncol] && grid[nrow][ncol]=='1'){
                        q.push({nrow, ncol});
                        visit[nrow][ncol] = 1;
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visit[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i, j, grid, visit);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends