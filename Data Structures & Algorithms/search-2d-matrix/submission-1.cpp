class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = (m * n) - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int mid_row = mid / n;
            int mid_col = mid % n;
            if(matrix[mid_row][mid_col] == target) return true;
            if(matrix[mid_row][mid_col] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return false;
    }
};
