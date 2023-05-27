//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    private:
    int helper(int index, int *arr, vector<int>& dp, int n){
        if(index == 0) return arr[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = arr[index] + helper(index-2, arr, dp, n);
        int notPick = 0 + helper(index-1, arr, dp, n);
        return dp[index] = max(pick, notPick);
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n+1, -1);
	    return helper(n-1, arr, dp, n );
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends