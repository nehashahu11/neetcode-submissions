class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                c -=1;
            else
                r +=1;
        }
        return false;
    }
};
