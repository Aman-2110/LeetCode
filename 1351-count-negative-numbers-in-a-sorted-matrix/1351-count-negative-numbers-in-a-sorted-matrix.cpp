class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0, row = 0, col = n - 1;
        while(row < m && col >= 0){
            if(grid[row][col] < 0){
                count += (m - row);
                col--;
            }else
                row++;
        }
        return count;
    }
};