class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // i ,j => j ,n - i - 1
        // j, n - i - 1 => n - i -1, n - j - 1
        // n - i -1, n - j - 1  => n - j - 1, i;
        //  n - j - 1, i => i, j
        /*
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < n - 1 - i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i -1][n - j - 1];
                matrix[n - i -1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
        return;*/

        //忘了上面那個複雜的映射吧， j 是個大坑。
        //拿一個盒子， 沿主軸轉置後水平翻轉就是順時鐘翻90度。
        //反過來，先水平翻在沿主軸轉置就是逆時鐘 90 度。
        int m = matrix.size();
        for(int i = 0; i < m; i++){
            for(int j = i; j < m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < m; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};
