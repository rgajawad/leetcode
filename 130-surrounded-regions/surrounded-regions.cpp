class Solution {
public:
    int m, n;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    void dfs(int r, int c, vector<vector<char>>& grid){
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 'O') return;
        grid[r][c] = '#';
        for(int k = 0; k < 4; k++){
            dfs(r + dr[k], c + dc[k], grid);
        }
    }
     
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            dfs(i, 0, board);
            dfs(i, n-1, board);
        }

        for(int i = 0; i < n; i++){
            dfs(0, i, board);
            dfs(m-1, i, board);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }


    }
};