class Solution { // Here are we are doing tabulation by shifting the index
public:
    // Space Optimiztion
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> prev(n2+1, 0), curr(n2+1, 0);
        for(int ind1=1; ind1<=n1; ind1++){
            for(int ind2=1; ind2<=n2; ind2++){
                if(text1[ind1-1] == text2[ind2-1]){
                    curr[ind2] = 1+prev[ind2-1];
                }
                else{
                    curr[ind2]=max(prev[ind2], curr[ind2-1]);
                }
            }
                prev = curr;
        }
        return prev[n2];
    }
};