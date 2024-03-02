class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(auto it:arr1){
            while(it>0){
                st.insert(it);
                it = it/10;
            }
        }
        int maxlen = 0;
        for(auto it:arr2){
            while(it){
                if(st.find(it)!=st.end()){
                    string temp = to_string(it);
                    int len = temp.length();
                    maxlen = max(maxlen, len);
                    break;
                }
                it=it/10;
            }
        }
        return maxlen;
    }
};