class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;
        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0, -1};
        auto dfs = [&](auto &self, int i, int j) -> void{            
            visited[i][j] = true;
            for(int dir = 0; dir < 4; dir++){
                int newX = i + dir_x[dir];
                int newY = j + dir_y[dir];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n &&
                grid[newX][newY] == '1' && !visited[newX][newY]){
                    self(self, newX, newY);
                }
            }
            return;
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(dfs, i, j);
                }
            }
        }

        return ans;
    }
};
