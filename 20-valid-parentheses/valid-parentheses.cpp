class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[') st.push(it);
            else{
                if(st.empty()) return false;
                int t=st.top();
                if(it==')'&& t=='(' || it==']'&& t=='[' || it=='}'&& t=='{') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};