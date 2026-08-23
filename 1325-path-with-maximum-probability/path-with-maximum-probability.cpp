class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            auto edge = edges[i];
            int u, v;
            u = edge[0], v = edge[1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
        vector<double> shortestCost(n, INT_MIN);
        shortestCost[start_node] = 1;
        priority_queue<pair<double,int>> pq;
        pq.push({1, start_node});
        while(pq.size()){
            auto [cost_so_far, u] = pq.top();
            pq.pop();
            for(auto [v, c] : adj[u]){
                double new_cost = cost_so_far*c;
                if(new_cost > shortestCost[v]){
                    shortestCost[v] = new_cost;
                    pq.push({new_cost, v});
                }
            }
        }
        if(shortestCost[end_node] == INT_MIN) return 0;
        return shortestCost[end_node];
        
    }
};