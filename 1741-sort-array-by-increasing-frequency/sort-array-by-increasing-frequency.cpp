
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxh;
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            maxh.push({it.second, -it.first});
        }
        while(!maxh.empty()){
            int freq = maxh.top().first;
            int elem = -maxh.top().second;
            for(int i=0; i<freq; i++){
                ans.push_back(elem);
            }
            maxh.pop();
        }
        return ans;
    }
};
