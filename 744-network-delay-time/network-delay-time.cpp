class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time: times){
            int u,v,w;
            u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> shortestDistance(n+1, INT_MAX);
        shortestDistance[k]=0;
        while(pq.size()){
            auto [cost,node] = pq.top();
            pq.pop();
            for(auto [v, w] : adj[node]){
                int new_cost = w + cost;
                if(new_cost >= shortestDistance[v]) continue;
                shortestDistance[v] = new_cost;
                pq.push({new_cost,v});
            }
        }
        int dist = 0;
        for(int i = 1; i <= n; i++){
            if(shortestDistance[i] == INT_MAX) return -1;
            dist = max(dist,shortestDistance[i]);
        }
        return dist;
    }
};