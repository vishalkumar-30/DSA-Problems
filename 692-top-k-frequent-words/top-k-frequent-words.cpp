class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int, string>> pq;
        for(auto &i:mp){
            pq.emplace(-i.second, i.first);
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans(pq.size());
        for(int i=pq.size()-1; i>=0; i--){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};