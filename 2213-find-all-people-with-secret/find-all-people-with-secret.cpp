class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meeting, int firstPerson) {
        vector<vector<pair<int, int>>>adj(n);
        for(int i=0; i<meeting.size(); i++){
            adj[meeting[i][0]].push_back({meeting[i][1], meeting[i][2]});
            adj[meeting[i][1]].push_back({meeting[i][0], meeting[i][2]});
        }
        vector<int>known(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        while(!pq.empty()){
            int person = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            if(known[person]) continue;
            known[person] = 1;
            for(auto [newPerson, newPrice]:adj[person]){
                if(!known[newPerson] && newPrice>=time){
                    pq.push({newPrice, newPerson});
                }
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if (known[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};