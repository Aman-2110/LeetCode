class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        cin.tie(0)->sync_with_stdio(false);
        cout.tie(0)->sync_with_stdio(false);
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[j][i] != 0){
                    matrix[j][i] += matrix[j - 1][i];
                }
            }
        }

        int res = 0;

        for(int i = 0 ; i < n ; i++){
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for(int j = 0 ; j < m ; j++)
                res = max((j + 1)*matrix[i][j], res);
        }
        return res;
    }
};