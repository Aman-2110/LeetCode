class TreeAncestor {
public:
    vector<vector<int>> up;
    vector<int> depth;
    int order;

    void dfs(int i, int dep, vector<vector<int>> &child){
        depth[i] = dep;

        for(int level = 1 ; level < order ; level++)
            up[i][level] = up[ up[i][level - 1] ][level - 1];
        
        for(int j : child[i])
            dfs(j, dep + 1, child);
    }

    TreeAncestor(int n, vector<int>& parent) {
        order = 20;
        up.resize(n, vector<int> (order));
        depth.resize(n);
        vector<vector<int>> child(n);
        up[0][0] = 0;
        for(int i = 1 ; i < n ; i++){
            child[parent[i]].push_back(i);
            up[i][0] = parent[i];
        }
        
        dfs(0, 0, child);
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k)
            return -1; 

        for(int i = 30 ; i != -1 ; i--){
            if(k & (1 << i))
                node = up[node][i];
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */