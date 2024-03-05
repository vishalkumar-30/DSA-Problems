class Solution {
public:
    void solve(vector<int>ip, vector<int>op, vector<vector<int>>& res){
        if(ip.size()==0){
            res.push_back(op);
            return;
        }
        vector<int>op1=op, op2=op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin());
        solve(ip, op1, res);
        solve(ip, op2, res);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
        vector<vector<int>>res;
        solve(nums, op, res);
        return res;
    }
};