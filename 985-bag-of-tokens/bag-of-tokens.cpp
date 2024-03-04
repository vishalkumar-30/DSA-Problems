class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        int l=0;
        int h=token.size()-1;
        int score = 0;
        sort(token.begin(), token.end());
        while(l <= h){
            if(power>=token[l]){
                score++;
                power -= token[l];
                l++;
            }else if(l<h && score>0){
                score--;
                power += token[h];
                h--;
            }else return score;
        }
        return score;
    }
};