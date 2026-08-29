class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshcnt = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    freshcnt++;
                }
            }
        }       
        if(freshcnt == 0) return 0; 

        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0, -1};
        int ans = -1;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int newX = x + dir_x[dir];
                    int newY = y + dir_y[dir];
                    if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                        if(grid[newX][newY] == 1){
                            grid[newX][newY] = 2;
                            freshcnt--;
                            q.push({newX, newY});
                        }
                    }
                }
            }            
        }

        return (freshcnt == 0) ? ans: -1;
    }
};
