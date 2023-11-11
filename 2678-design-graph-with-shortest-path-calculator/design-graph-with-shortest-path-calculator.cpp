class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &v : edges)
            adj[v[0]].push_back({v[1], v[2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        cin.tie(0)->sync_with_stdio(false);
        cout.tie(0)->sync_with_stdio(false);
        vector<int> dist(adj.size(), INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push({0, node1});
        dist[node1] = 0;
        while(!que.empty()){
            auto [a, b] = que.top();
            que.pop();
            if(b == node2)
                return a;

            for(auto [neigh, cost] : adj[b]){
                if(dist[neigh] > a + cost){
                    que.push({a + cost, neigh});
                    dist[neigh] = a + cost;
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */