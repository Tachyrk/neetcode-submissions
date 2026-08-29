class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> checked(m, vector<int>(n, -1));       

        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0, -1};
        auto dfs = [&](auto &self, int x, int y)->void{
            if(checked[x][y] != -1){
                return ;
            }
            checked[x][y] = 0;
            if(x == 0 || y == 0) checked[x][y] |= 1;
            if(x == m - 1 || y == n - 1) checked[x][y] |= 2;
            for(int dir = 0; dir < 4; dir++){                
                int newX = x + dir_x[dir];
                int newY = y + dir_y[dir];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                    if(heights[newX][newY] <= heights[x][y]){
                        self(self, newX, newY);
                        checked[x][y] |= checked[newX][newY];
                    }
                }
            }            
        };

        vector<vector<int>> ans;
        ans.reserve(m * n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(checked[i][j] == -1){
                    dfs(dfs, i, j);
                }
               
                if(checked[i][j] == 3){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
