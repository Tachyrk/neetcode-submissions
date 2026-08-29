class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = '*';
            }            
            if(board[i][n - 1] == 'O'){
                q.push({i, n - 1});
                board[i][n - 1] = '*';
            }    
        }
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                board[0][i] = '*';
            }            
            if(board[m - 1][i] == 'O'){
                q.push({m - 1, i});
                board[m - 1][i] = '*';
            }    
        }

        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0, -1};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int newX = x + dir_x[dir];
                int newY = y + dir_y[dir];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                    if(board[newX][newY] == 'O'){
                        board[newX][newY] = '*';
                        q.push({newX, newY});
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }                
            }
        }
    }
};
