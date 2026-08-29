class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> status(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            status[0][i] |= 1;
            status[m - 1][i] |= 2;
            if(m == 1){
                q.push({0, i});
            }else{
                q.push({0, i});
                q.push({m - 1, i});
            }
        }

        for(int i = 0; i < m; i++){
            status[i][0] |= 1;
            status[i][n - 1] |= 2;
            if(n == 1){
                q.push({i, 0});
            }else{
                q.push({i, 0});
                q.push({i, n - 1});
            }
        }

        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0 ,-1};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int newX = x + dir_x[dir];
                int newY = y + dir_y[dir];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                    if(heights[newX][newY] >= heights[x][y]){   
                        int oldstate =  status[newX][newY];                  
                        status[newX][newY] |= status[x][y];
                        if(oldstate != status[newX][newY]){
                            q.push({newX, newY});
                        }
                    }
                    
                }
            }
        }

        vector<vector<int>> ans;
        ans.reserve(m*n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(status[i][j] == 3){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
