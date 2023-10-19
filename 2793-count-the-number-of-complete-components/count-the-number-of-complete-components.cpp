class Solution {
public:
    int dfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dp){
        if(vis[i])
            return 0;

        vis[i] = true;

        int c = 1;

        for(auto j : adj[i]){
            c += dfs(j, adj, vis, dp);
        }

        return dp[i] = c;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, false);
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                vector<int> dp(n, -1);
                dfs(i, adj, vis, dp);
                int c = dp[i];
                bool flag = true;
                for(int j = 0 ; j < n ; j++){
                    if(dp[j] != -1){
                        if(adj[j].size() != c - 1)
                            flag = false;
                    }
                }

                if(flag)
                    res++;

            }
        }

        return res;
    }
};