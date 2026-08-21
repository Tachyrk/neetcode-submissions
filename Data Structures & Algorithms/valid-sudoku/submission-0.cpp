class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowcheck(9, vector<bool>(10, false)); 
        vector<vector<bool>> colcheck(9, vector<bool>(10, false)); 
        vector<vector<bool>> blockcheck(9, vector<bool>(10, false)); 
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int element = board[i][j] - '0';
                    int block = (i / 3) * 3 + (j / 3);
                    if(rowcheck[i][element] == true) return false;
                    if(colcheck[j][element] == true) return false;
                    if(blockcheck[block][element] == true) return false;
                    rowcheck[i][element] = true;
                    colcheck[j][element] = true;
                    blockcheck[block][element] = true;
                }
            }
        }

        return true;
    }
};
