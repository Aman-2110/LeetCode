class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

        
        for(auto p : adj[0])
            que.push({p.second, p.first});
        
        int res = 0;
        vector<bool> vis(n);
        vis[0] = true;

        while(!que.empty()){
            auto p = que.top();
            que.pop();

            if(vis[p.second])
                continue;

            res += p.first;
            vis[p.second] = true;

            for(auto q : adj[p.second]){
                if(!vis[q.first])
                    que.push({q.second, q.first});
            }
        }

        return res;
    }
};