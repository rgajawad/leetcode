class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto edge: times){
            int u, v, w;
            u = edge[0]-1, v = edge[1]-1, w = edge[2];
            adj[u].push_back({v, w});
        }
        
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[k-1] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k-1});

        while(pq.size()){
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for(auto [v, w] : adj[u]){
                if(dist[u] + w  < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int max_dist = dist[0];
        for(int d : dist){
            if(d == INF) return -1;
            max_dist = max(d, max_dist);
        }
        return max_dist;

    }
};