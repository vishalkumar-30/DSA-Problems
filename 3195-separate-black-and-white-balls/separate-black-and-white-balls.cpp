// class Solution {
// public:
//     long long minimumSteps(string s) {
//         int ans=0, k=s.size();
//         int t = s.size();
//         while(t--){
//             int i=0, j=1;
//         while(j<k){
//             if(s[i]=='1' && s[j]=='0'){
//                 swap(s[i], s[j]);
//                 ans++;
//             //    k--;
//             }
//             i++; j++;
//         }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
            } else {
                ans += count;
            }
        }
        return ans;
    }
};

