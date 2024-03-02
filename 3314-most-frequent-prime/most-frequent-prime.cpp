class Solution {
public:
    bool isPossible(int x, int y, int row, int col){
        return x>=0 && x<row && y>=0 && y<col;
    }
    bool isPrime(int x){
        if(x <= 1) return false;
        if(x == 2) return true;
        if(x % 2 == 0) return false;
        for(int i = 3; i * i <= x; i += 2){
            if(x % i == 0) return false;
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int, int> fq;
        int dirX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dirY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 8; k++){
                    int temp = mat[i][j];
                    int x = i + dirX[k];
                    int y = j + dirY[k];
                    
                    while(isPossible(x, y, m, n)){
                        temp = temp*10 + mat[x][y];
                        if(temp > 10 && isPrime(temp)) {
                            // number = temp;
                            fq[temp]++;
                        }
                        x += dirX[k];
                        y += dirY[k];
                    }
                }
            }
        }
        int freq = 0;
        int ans = -1;
        for(auto it : fq){
            if(it.second > freq || (it.second == freq && it.first > ans)){
                freq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};
