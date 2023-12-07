class Solution {
private:
bool isVowel(char c){
    if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}
public:
    int beautifulSubstrings(string s, int k) {
        int ans=0;
        for(int i=0; i<s.size(); i++){
            int c=0, v=0;
            for(int j=i; j<s.size(); j++){
                if(isVowel(s[j])) c++;
                else v++;
                if(v == c){
                    if((v*c)%k == 0) ans++;
                }
            }
        }
        return ans;
    }
};