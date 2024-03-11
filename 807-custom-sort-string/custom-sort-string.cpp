class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        for(auto it:s) mp[it]++;
        string res = "";
        for(int i=0; i<order.size(); i++){
            while(i<order.length() && mp[order[i]]>0){
                while(mp[order[i]]){
                    res.push_back(order[i]);
                    mp[order[i]]--;
                }
                i++;
            }
        }
        for(auto &i:mp){
            while(i.second>0){
                res.push_back(i.first);
                i.second--;
            }
        }
        return res;
    }
};