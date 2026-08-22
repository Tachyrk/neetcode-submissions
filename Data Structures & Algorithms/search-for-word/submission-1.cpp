class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int x_dir[4] = {1, -1, 0, 0};
        int y_dir[4] = {0, 0, 1, -1};
        auto dfs = [&](auto &self, int i, int j, int index)->bool{            
            if(board[i][j] != word[index]) return false;
            if(index == word.size() - 1) return true;      
            visited[i][j] = true;      
            for(int dir = 0; dir < 4; dir++){
                int newx = i + x_dir[dir];
                int newy = j + y_dir[dir];
                if(newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
                if(visited[newx][newy]) continue;
                
                if(self(self, newx, newy, index + 1)){
                    return true;
                }
                
            }
            visited[i][j] = false;
            return false;
        };

        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(dfs(dfs, x, y, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
