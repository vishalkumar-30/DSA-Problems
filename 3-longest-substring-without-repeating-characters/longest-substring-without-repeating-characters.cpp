class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>hash;
        int i=0, j=0, ans=0;
        for(i=0; i<s.length(); i++){
            hash[s[i]]++;
            while(hash[s[i]]>1){
                hash[s[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};