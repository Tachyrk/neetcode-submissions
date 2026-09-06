class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col_0_has_zero = false;
        bool row_0_has_zero = false;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) row_0_has_zero = true;
                    if(j == 0) col_0_has_zero = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            if(matrix[0][i] == 0){
                for(int j = 0; j < m; j++){
                    matrix[j][i] = 0;
                }
            }
        }

        if(col_0_has_zero){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }

        if(row_0_has_zero){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }

        return;
    }
};
