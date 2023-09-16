class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector vis(m, vector<int> (n, INT_MAX));
        vis[0][0] = 0;
        int dirX[4] = {-1, 1, 0, 0}, dirY[4] = {0, 0, 1, -1};
        queue<tuple<int, int, int>> que;
        que.push({0, 0, 0});
        while(!que.empty()){
            auto [a, b, c] = que.front();
            que.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nx = a + dirX[i];
                int ny = b + dirY[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int t = max(vis[a][b], abs(heights[a][b] - heights[nx][ny]));
                    if(vis[nx][ny] > t){
                        vis[nx][ny] = t;
                        que.push({nx, ny, t});
                    }
                }
            }
        }

        return vis[m -1][n - 1];
    }
};