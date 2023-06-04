//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
// private:
//     bool function(int ind, vector<int>& arr, int sum, vector<vector<int>>&dp){
//         if(sum == 0) return true;
//         if(ind == 0) return (arr[0] == sum);
//         if(dp[ind][sum] != -1) return dp[ind][sum];
//         bool notTake = function(ind-1, arr, sum, dp);
//         bool take = false;
//         if(arr[ind] <= sum) take = function(ind-1, arr, sum-arr[ind], dp);
//         return dp[ind][sum]=take || notTake;
//     }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1, 0));
        for(int i=0; i<n; i++) dp[i][0]=true;
        if(arr[0]  <= sum) dp[0][arr[0]] = true;
        
        for(int ind=1; ind<n; ind++){
            for(int target = 1; target<=sum; target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
                dp[ind][target]=take || notTake; 
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends