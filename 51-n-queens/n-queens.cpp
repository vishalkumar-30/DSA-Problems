class Solution {
public:
bool isSafe(int row, int col, vector<string>& board, int n){
    int r = row, c = col;
    while(r>=0 && c>=0){
        if(board[r][c]=='Q') return false;
        r--; c--;
    }
    r=row; c=col;
    while(c>=0){
        if(board[r][c]=='Q') return false;
        c--;
    }
    r=row; c=col;
    while(r<n && c>=0){
        if(board[r][c]=='Q') return false;
        r++; c--;
    }
    return true;
} 
    void solve(int col, vector<string>& board, vector<vector<string>>& res, int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, res, n);
                board[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        solve(0, board, res, n);
        return res;
    }
};