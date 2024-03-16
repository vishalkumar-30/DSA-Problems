class Solution {
public:
    string minimizeStringValue(string s) {
        int count[26] = {0};
        int k = 0;
       
        for(char c: s){ 
            if(c == '?') k++;
            else count[c-'a']++;
        }
        
        int unused[26] = {0};
        while(k--){
            int minidx=0;
            for(int i=1; i<26; i++){
                if(count[i]<count[minidx]) minidx = i;
            }
            count[minidx]++; unused[minidx]++;
        }
        int j = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '?'){
                while(!unused[j])j++;
                unused[j]--;
                s[i] = 'a'+j;
            }
        }
        return s;
    }
};