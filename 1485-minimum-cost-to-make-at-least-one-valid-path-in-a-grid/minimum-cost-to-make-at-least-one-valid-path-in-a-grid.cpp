class Solution {

private:
  bool isValid(int x, int y, int m, int n){
    return x >= 0 && y >= 0 && x < m && y < n;
  }

    bool edgeCost(int val, int dx, int dy){
        if(val == 1 && dx == 0 && dy == 1){
            return 0;
        }
        if(val == 2 && dx == 0 && dy == -1){
            return 0;
        }

        if(val == 3 && dx == 1 && dy == 0){
            return 0;
        }

        if(val == 4 && dx == -1 && dy == 0){
            return 0;
        }
        return 1;

    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        while(dq.size()){
            auto [x, y] = dq.front();
            dq.pop_front();
            vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
            for(int i = 0; i < 4; i++){
                auto [dx,dy] = dirs[i];
                int nr, nc;
                nr = x + dx, nc = y + dy;
                int cost = edgeCost(grid[x][y], dx, dy);
                if(isValid(nr,nc, m, n)){
                    if(dist[x][y] + cost < dist[nr][nc]){
                        dist[nr][nc] = dist[x][y] + cost;
                        if(cost == 0){
                            dq.push_front({nr, nc});
                        }
                        else{
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        return dist[m-1][n-1];

        
    }
};