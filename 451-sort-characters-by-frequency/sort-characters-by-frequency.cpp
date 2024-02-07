class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(char c:s) mp[c]++;
        vector<vector<char>> bucket(n+1);
        for(auto [c, f] : mp) bucket[f].push_back(c);
        string ans;
        for (int freq = n; freq >= 1; --freq)
            for (char c : bucket[freq]) 
                ans.append(freq, c);
        return ans;
    }
};