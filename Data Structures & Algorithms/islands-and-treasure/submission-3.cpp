class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int INF = 2147483647;

        // 直接存 x, y 的組合
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0, -1};
        while(!q.empty()){
            // 利用 C++17 語法直接解構取出 x, y
            auto [x, y] = q.front();
            q.pop();
            
            int dis = grid[x][y];
            for(int dir = 0; dir < 4; dir++){
                int newX = x + dir_x[dir];
                int newY = y + dir_y[dir];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                    if(grid[newX][newY] == INF){
                        grid[newX][newY] = dis + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
    }
};