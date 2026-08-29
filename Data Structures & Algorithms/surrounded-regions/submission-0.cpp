class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0, -1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && visited[i][j] == false){
                    queue<pair<int, int>> q;
                    queue<pair<int, int>> backup_q;
                    q.push({i, j});
                    visited[i][j] = true;
                    backup_q.push({i, j});
                    bool closed = true;

                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();                        
                        if(x == 0 || y == 0 || x == m - 1 || y == n - 1){
                            closed = false;
                        }
                        for(int dir = 0; dir < 4; dir++){
                            int newX = x + dir_x[dir];
                            int newY = y + dir_y[dir];
                            if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                                if(board[newX][newY] == 'O' && !visited[newX][newY]){
                                    visited[newX][newY] = true;
                                    q.push({newX, newY});
                                    backup_q.push({newX, newY});
                                }
                            }
                        }
                    }

                    if(closed){
                        while(!backup_q.empty()){
                            auto [x, y] = backup_q.front();
                            backup_q.pop();    
                            board[x][y] = 'X';
                        }
                    }
                }
            }
        }
    }
};
