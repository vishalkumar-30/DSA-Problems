class Solution {
public:
bool check(string s, int l, int h){
    while(l<=h){
        if(s[l++]!=s[h--]) return false;
    }
    return true;
}
void solve(int ind, string s, vector<string>ans, vector<vector<string>>& res){
    if(ind ==s.size()){
        res.push_back(ans);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        if(check(s, ind, i)){
            ans.push_back(s.substr(ind, i-ind+1));
            solve(i+1, s, ans, res);
            ans.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ans;
        solve(0, s, ans, res);
        return res;
    }
};