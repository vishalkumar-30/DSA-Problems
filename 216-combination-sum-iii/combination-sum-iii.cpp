class Solution {
private:
    void helper(int ind, int k, int n, vector<vector<int>> &res, vector<int> &temp){
        if(n==0 && k==0){
            res.push_back(temp);
            return;
        }
        if(n<0 || k<0) return;
        for(int i=ind; i<10; i++){
            temp.push_back(i);
            helper(i+1, k-1, n-i, res, temp);
            temp.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;
        helper(1, k, n, res, temp);
        return res;
    }
};