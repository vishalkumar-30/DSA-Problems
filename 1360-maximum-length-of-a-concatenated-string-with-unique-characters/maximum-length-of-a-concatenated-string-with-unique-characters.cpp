class Solution {
    private:
    bool isUnique(string s){
        set<char> st;
        for(auto it: s){
            if(st.find(it) != st.end()) return false;
            st.insert(it);
        }
        return true;
    }
    void check(string s, vector<string> &arr, int ind, int &len){
        if(!isUnique(s)) return;
        if(s.size() > len) len = s.size();
        for(int i=ind; i<arr.size(); i++){
            check(s+arr[i], arr, i+1, len);
        }
    }
public:
    int maxLength(vector<string>& arr) {
        int len = 0;
        check("", arr, 0, len);
        return len;
    }
};