//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int i, int j, int arr[], vector<vector<int>> &dp) {
        if (i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int steps = INT_MAX; // Using INT_MAX instead of 1e9
        for (int k = i; k < j; k++) { // Changed loop initialization from 1 to i
            int ans = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            if (ans < steps) steps = ans;
        }

        return dp[i][j]=steps;
    }

public:
    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>>dp(N, vector<int>(N, -1));
        return f(1, N - 1, arr, dp); // Changed initial indices to 1 and N-1
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends