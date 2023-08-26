class Solution {
public:
    int dirX[4] = {-1, 1, 0, 0}, dirY[4] = {0, 0, -1, 1};
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;
        for(int k = 0 ; k < 4 ; k++){
            int nr = i + dirX[k];
            int nc = j + dirY[k];
            if(nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size() && matrix[nr][nc] > matrix[i][j]){
                maxi = max(maxi, 1 + dfs(nr, nc, matrix, dp));
            }
        }
        return dp[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> que;
        vector dp(m, vector<int> (n, -1));
        int maxi = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(dp[i][j] == -1)
                    maxi = max(maxi, 1 + dfs(i, j, matrix, dp));
            }
        }
        return maxi;
    }
};