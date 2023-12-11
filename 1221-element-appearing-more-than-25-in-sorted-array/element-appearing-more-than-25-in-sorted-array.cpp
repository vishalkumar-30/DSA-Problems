class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int it:arr) mp[it]++;
        int temp = arr.size()/4;
        for(auto& [k, val]: mp){
            if(val > temp) return k;
        }
        return -1;
    }
};