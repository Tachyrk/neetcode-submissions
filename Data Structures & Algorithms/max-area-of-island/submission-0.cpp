class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n , false));
        
        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0, -1};
        auto dfs = [&](auto &self, int x, int y)->int{
            if(visited[x][y]) return 0;
            visited[x][y] = true;
            int cnt = 1;
            for(int dir = 0; dir < 4; dir++){
                int newx = x + dir_x[dir];
                int newy = y + dir_y[dir];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1 && !visited[newx][newy]){
                    cnt += self(self, newx, newy);
                }
            }
            return cnt;
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    ans = max(ans, dfs(dfs, i, j));
                }
            }
        }
        return ans;
    }
};
