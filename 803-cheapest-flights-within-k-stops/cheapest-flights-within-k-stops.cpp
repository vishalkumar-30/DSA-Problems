class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int>dist(n, 1e9);
        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        dist[src]=0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}});
        
        int ans = INT_MAX;

        while (!q.empty()) {
            int stop = q.front().first;
            int price = q.front().second.first;
            int node = q.front().second.second;
            q.pop();

            if (stop > k) continue; //k=0

            // if (node == dst) {
            //     ans = min(ans, price);
            // }

            for (auto [newNode, newPrice] : adj[node]) {
                if(dist[newNode] > price + newPrice){
                    dist[newNode] = price + newPrice;
                    q.push({stop + 1, {price + newPrice, newNode}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};