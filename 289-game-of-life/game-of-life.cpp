class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dirX[] = {-1, 0, 1, -1, 1, -1, 0, 1}, dirY[] = {-1, -1, -1, 0, 0, 1, 1, 1}, m = board.size(), n = board[0].size();

        vector<pair<int, int>> flip;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int c = 0;
                for(int k = 0 ; k < 8 ; k++){
                    int nr = i + dirX[k];
                    int nc = j + dirY[k];
                    
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 1)
                        c++;
                }

                if((board[i][j] == 0 && c == 3) || (board[i][j] == 1 && (c < 2 || c > 3)))
                    flip.push_back({i, j});
            }
        }

        for(auto p : flip){
            if(board[p.first][p.second] == 1)
                board[p.first][p.second] = 0;
            else
                board[p.first][p.second] = 1;
        }
    }
};