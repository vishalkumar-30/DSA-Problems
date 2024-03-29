//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool bfs(int s, vector<int> adj[], int vis[]){
        vis[s]=1;
        queue<pair<int, int>> q;
        q.push({s, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNode:adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode, node});
                }
                else if(parent != adjNode){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int node, int parent, vector<int> adj[], int vis[]){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it, node, adj, vis)){
                    return true;
                }
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis)) return true; 
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends