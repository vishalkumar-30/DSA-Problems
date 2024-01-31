class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>>s;   // arr, indx
        vector<int> ans;
        int n = temp.size();
        for(int i=n-1; i>=0; i--){
            if(s.empty()) ans.push_back(0);
            else if (s.size()>0 && s.top().first > temp[i]) {
                ans.push_back(s.top().second - i);
            }
            else if (s.size()>0 && s.top().first<=temp[i]){
                while(s.size()>0 && s.top().first<=temp[i]) s.pop();
                if(s.size()==0) ans.push_back(0);
                else ans.push_back(s.top().second - i);
            }
            s.push({temp[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};