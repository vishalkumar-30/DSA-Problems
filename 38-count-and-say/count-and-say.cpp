class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=2; i<=n; i++){
            string prev = ans;
            int s = ans.size();
            int j=0;
            ans = "";
            while(j<s){
                int k = j;
                while(k<s && prev[k]==prev[j]){
                    k++;
                }
                ans = ans + to_string(k-j) + prev[j];
                j=k;
            }
        }
        return ans;
    }
};