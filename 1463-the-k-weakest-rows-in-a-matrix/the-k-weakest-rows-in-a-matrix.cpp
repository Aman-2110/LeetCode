class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<pair<int, int>> que;
        for(int i = 0 ; i < m ; i++){
            int count = 0;
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0)
                    break;
                else
                    count++;
            }
            que.push({count, i});
            while(que.size() > k)
                que.pop();
        }

        vector<int> res;
        while(!que.empty()){
            res.push_back(que.top().second);
            que.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};