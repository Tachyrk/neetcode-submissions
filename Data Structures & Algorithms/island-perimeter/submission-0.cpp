class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        int x_dir[4] = {1, 0, -1, 0};
        int y_dir[4] = {0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(int nd = 0; nd < 4; nd++){
                        int newx = i + x_dir[nd];
                        int newy = j + y_dir[nd];
                        if(newx >= 0 && newx < m && newy >= 0 && newy < n){
                            if(grid[newx][newy] == 0) ans++;
                        }else{
                            ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};