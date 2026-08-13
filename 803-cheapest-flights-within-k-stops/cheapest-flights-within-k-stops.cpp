

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(101);
        for(auto f : flights){
            int from, to, price;
            from = f[0], to = f[1], price = f[2];
            adj[from].push_back({to, price});
        }
        vector<vector<int>> shortestDistance(n, vector<int>(k+2,INT_MAX));
        shortestDistance[src][0] = 0;
        // 
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});
        while(pq.size()){
            auto [cost, node, flightsUsed] = pq.top();
            pq.pop();

            if(flightsUsed >= k+1) continue;
            for(auto [v, weight]: adj[node]){
                int new_cost = weight + cost;
                if(new_cost < shortestDistance[v][flightsUsed+1]){
                    shortestDistance[v][flightsUsed+1] = new_cost;
                    pq.push({new_cost, v,flightsUsed+1});
                }
            }
            
        }
        int mx = shortestDistance[dst][0];
        for(int x = 1; x <= k+1; x++){
            mx = min(mx, shortestDistance[dst][x]);
        }
        if(mx == INT_MAX) return -1;
        return mx;

    }
};