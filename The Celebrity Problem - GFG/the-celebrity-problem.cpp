//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool pehchan(int x, int y, vector<vector<int>> &nums){
        if(nums[x][y] ==1) return true;
        else return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0; i<M.size(); i++){
            st.push(i);
        }
        while(st.size()>1){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if(pehchan(x, y, M)) st.push(y);
            else st.push(x);
        }
        int ans = st.top();
        int zero=0;
        for(int i=0; i<n; i++){
            if(M[ans][i] == 0) zero++;
        }
        if(zero != n) return -1;
        int one = 0;
        for(int i=0; i<n; i++){
            if(M[i][ans] == 1) one++;
        }
        if(one != n-1) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends