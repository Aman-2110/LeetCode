class Solution {
public:
    int dfs(int i, int p, vector<vector<pair<int, bool>>> &adj){
        int count = 0;

        for(auto j : adj[i]){
            if(j.first != p){
                count += (j.second ? 0 : 1) + dfs(j.first, i, adj);
            }
        }

        return count;
    }



    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, bool>>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1], true});
            adj[edge[1]].push_back({edge[0], false});
        }

        int a = dfs(0, -1, adj);
        cout << a << endl;
        vector<int> res(n, -1);
        res[0] = a;
        queue<pair<int, int>> que;
        que.push({0, a});

        while(!que.empty()){
            auto p = que.front();
            que.pop();
            for(auto j : adj[p.first]){
                if(res[j.first] == -1){
                    res[j.first] = p.second + (j.second ? 1 : -1);
                    que.push({j.first, res[j.first]});
                }
            }
        }

        return res;
    }
};