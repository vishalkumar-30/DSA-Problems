class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        int ans=0, prev=0;
        for(int i=m-1; i>=0; i--){
            int cnt=0;
            for(int j=n-1; j>=0; j--){
                if(bank[i][j] == '1')cnt++;
            }
            if(cnt!=0) ans += prev*cnt;
            if(cnt != 0){
                prev = cnt;
            }
        }
        return ans;
    }
};