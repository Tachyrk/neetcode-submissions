class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        visited[0][0] = grid[0][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({grid[0][0], 0});

        int x_dir[4] = {1, 0, -1, 0};
        int y_dir[4] = {0, 1, 0, -1};
        while(!pq.empty()){
            auto [current_t, current] = pq.top();
            pq.pop();
            int x = current / m;
            int y = current % m;            
            for(int dir = 0; dir < 4; dir++){
                int new_x = x + x_dir[dir];
                int new_y = y + y_dir[dir];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                    if (max(current_t, grid[new_x][new_y]) < visited[new_x][new_y]){
                        visited[new_x][new_y] = max(current_t, grid[new_x][new_y]);
                        pq.push({visited[new_x][new_y], new_x * m + new_y});
                    }
                }
            }
        }

        return visited[m - 1][n - 1];
    }
};
