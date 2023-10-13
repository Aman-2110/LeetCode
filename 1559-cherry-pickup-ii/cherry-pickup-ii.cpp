class Solution {
public:
    int dirY[3] = {-1, 0, 1};
    int helper(int i, int j1, int j2, vector<vector<int>>& grid, int*** dp, int m, int n){
        if(i == m)
            return 0;
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = 0;

        for(int k = 0 ; k < 3 ; k++){
            for(int l = 0 ; l < 3 ; l++){
                if(j1 + dirY[k] >= 0 && j1 + dirY[k] < n && j2 + dirY[l] >= 0 && j2 + dirY[l] < n)
                    maxi = max(maxi, helper(i + 1, j1 + dirY[k], j2 + dirY[l], grid, dp, m, n));
            }
        }

        return dp[i][j1][j2] = (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]) + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int*** dp = new int**[m];

        for(int i = 0; i < m; i++){
            dp[i] = new int*[n];
            for(int j = 0; j < n; j++){
                dp[i][j] = new int[n]; 
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        return helper(0, 0, n - 1, grid, dp, m, n);
    }
};