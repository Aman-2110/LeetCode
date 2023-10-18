class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> startTime(n, 0), indegree(n, 0);
        for(auto v : relations){
            adj[v[0] - 1].push_back(v[1] - 1);
            indegree[v[1] - 1]++;
        }

        queue<pair<int, int>> que;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0)
                que.push({i, 0});
        }

        int res = 0;
        while(!que.empty()){
            auto [i, t] = que.front();
            que.pop();

            res = max(res, t + time[i]);

            for(auto j : adj[i]){
                indegree[j]--;
                startTime[j] = max(startTime[j], t + time[i]);
                if(indegree[j] == 0){
                    que.push({j, startTime[j]});
                }
            }
        }

        return res;
    }
};