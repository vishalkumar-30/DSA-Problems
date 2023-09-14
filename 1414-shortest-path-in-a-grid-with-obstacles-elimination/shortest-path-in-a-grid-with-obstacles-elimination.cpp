#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0, k});
        visited[0][0][k] = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int d = cur[0], x = cur[1], y = cur[2], rest = cur[3];
            if (x == m - 1 && y == n - 1) return d;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int nrest = rest - grid[nx][ny];
                if (nrest >= 0 && d + 1 < visited[nx][ny][nrest]) {
                    visited[nx][ny][nrest] = d + 1;
                    pq.push({d + 1, nx, ny, nrest});
                }
            }
        }
        return -1;
    }
private:
    vector<int> dx{0, -1, 0, 1}, dy{-1, 0, 1, 0};
};
