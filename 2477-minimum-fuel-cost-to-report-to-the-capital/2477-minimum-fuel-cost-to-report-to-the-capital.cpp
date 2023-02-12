class Solution {
public:
    int dfs(int curr, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &count){
        int child = 1;
        
        for(auto i : adj[curr]){
            if(!vis[i]){
                vis[i] = true;
                child += dfs(i, adj, vis, count);
            }
                
        }
        
        return count[curr] = child;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        
        vector<vector<int>> adj(n);
        
        for(auto vctr : roads){
            adj[vctr[0]].push_back(vctr[1]);
            adj[vctr[1]].push_back(vctr[0]);
        }
        
        vector<int> count(n);
        vector<bool> vis(n, false);
        vis[0] = true;
        dfs(0, adj, vis, count);  
        
        long long res = 0;
        for(int i = 1 ; i < n ; i++){
            res += ceil(count[i]*1.0/seats);
        }
        return res;
    }
};