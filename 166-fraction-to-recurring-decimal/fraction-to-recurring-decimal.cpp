class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num == 0) return "0";
        string ans;
        bool flag = (num<0 && den>=0) || (num>=0 && den<0);
        long long n = num;
        long long d = den;
        n = abs(n);
        d = abs(d);
        long long q = n/d;
        long long r = n%d;
        ans = to_string(q);
        unordered_map<long long int, int> mp;
        if(r == 0) return (flag ? '-' + ans : ans);
        else {
            ans.push_back('.');
            while(r != 0){
                if(mp.find(r) != mp.end()){
                    int p = mp[r];
                    ans = ans.substr(0,p) + '(' + ans.substr(p) + ')';
                    break;
                }
                else{
                    mp[r] = ans.size();
                    r *= 10;
                    q = r/d;
                    r = r%d;
                    ans += to_string(q);
                }
            }
        }
        if(flag) ans.insert(ans.begin(), '-');
        return ans;
    }
};